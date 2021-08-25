/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2008 Alexander Dymo <adymo@kdevelop.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/
#include "kshortcutsdialog_p.h"

#include <QDir>
#include <QLabel>
#include <QMenu>
#include <QFile>
#include <QPushButton>
#include <QTextStream>
#include <QDomDocument>
#include <QFileDialog>
#include <QStandardPaths>
#include <QInputDialog>
#include <QComboBox>

#include <kconfiggroup.h>
#include <kmessagebox.h>
#include <ksharedconfig.h>

#include "kshortcutsdialog.h"
#include "kshortcutschemeshelper_p.h"
#include "kactioncollection.h"
#include "kxmlguiclient.h"
#include <debug.h>

KShortcutSchemesEditor::KShortcutSchemesEditor(KShortcutsDialog *parent)
    : QGroupBox(i18nc("@title:group", "Shortcut Schemes"), parent), m_dialog(parent)
{
    KConfigGroup group(KSharedConfig::openConfig(), "Shortcut Schemes");

    QStringList schemes;
    schemes << QStringLiteral("Default");
    // List files in the shortcuts subdir, each one is a scheme. See KShortcutSchemesHelper::{shortcutSchemeFileName,exportActionCollection}
    const QStringList shortcutsDirs = QStandardPaths::locateAll(QStandardPaths::GenericDataLocation, QCoreApplication::applicationName() + QLatin1String("/shortcuts"), QStandardPaths::LocateDirectory);
    qCDebug(DEBUG_KXMLGUI) << "shortcut scheme dirs:" << shortcutsDirs;
    for (const QString &dir : shortcutsDirs) {
        const auto files = QDir(dir).entryList(QDir::Files | QDir::NoDotAndDotDot);
        for (const QString &file : files) {
            qCDebug(DEBUG_KXMLGUI) << "shortcut scheme file:" << file;
            schemes << file;
        }
    }

    const QString currentScheme = group.readEntry("Current Scheme", "Default");
    qCDebug(DEBUG_KXMLGUI) << "Current Scheme" << currentScheme;

    QHBoxLayout *l = new QHBoxLayout(this);

    QLabel *schemesLabel = new QLabel(i18n("Current scheme:"), this);
    l->addWidget(schemesLabel);

    m_schemesList = new QComboBox(this);
    m_schemesList->setEditable(false);
    m_schemesList->addItems(schemes);
    m_schemesList->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    const int schemeIdx = m_schemesList->findText(currentScheme);
    if (schemeIdx > -1) {
        m_schemesList->setCurrentIndex(schemeIdx);
    } else {
        qCWarning(DEBUG_KXMLGUI) << "Current scheme" << currentScheme << "not found in" << shortcutsDirs;
    }
    schemesLabel->setBuddy(m_schemesList);
    l->addWidget(m_schemesList);

    m_newScheme = new QPushButton(i18nc("@action:button", "New..."));
    l->addWidget(m_newScheme);

    m_deleteScheme = new QPushButton(i18nc("@action:button", "Delete"));
    l->addWidget(m_deleteScheme);

    QPushButton *moreActions = new QPushButton(i18nc("@action:button", "More Actions"));
    l->addWidget(moreActions);

    QMenu *moreActionsMenu = new QMenu(this);
    moreActionsMenu->addAction(i18nc("@action:inmenu", "Save shortcuts to scheme"),
                               this, &KShortcutSchemesEditor::saveAsDefaultsForScheme);
    moreActionsMenu->addAction(i18nc("@action:inmenu", "Export Scheme..."),
                               this, &KShortcutSchemesEditor::exportShortcutsScheme);
    moreActionsMenu->addAction(i18nc("@action:inmenu", "Import Scheme..."),
                               this, &KShortcutSchemesEditor::importShortcutsScheme);
    moreActions->setMenu(moreActionsMenu);

    l->addStretch(1);

#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
    connect(m_schemesList, QOverload<const QString &>::of(&QComboBox::activated),
            this, &KShortcutSchemesEditor::shortcutsSchemeChanged);
#else
    connect(m_schemesList, &QComboBox::textActivated,
            this, &KShortcutSchemesEditor::shortcutsSchemeChanged);
#endif
    connect(m_newScheme, &QPushButton::clicked, this, &KShortcutSchemesEditor::newScheme);
    connect(m_deleteScheme, &QPushButton::clicked, this, &KShortcutSchemesEditor::deleteScheme);
    updateDeleteButton();
}

void KShortcutSchemesEditor::newScheme()
{
    bool ok;
    const QString newName = QInputDialog::getText(this, i18nc("@title:window", "Name for New Scheme"),
                            i18n("Name for new scheme:"), QLineEdit::Normal, i18n("New Scheme"), &ok);
    if (!ok) {
        return;
    }

    if (m_schemesList->findText(newName) != -1) {
        KMessageBox::sorry(this, i18n("A scheme with this name already exists."));
        return;
    }

    const QString newSchemeFileName = KShortcutSchemesHelper::writableApplicationShortcutSchemeFileName(newName);
    QDir().mkpath(QFileInfo(newSchemeFileName).absolutePath());
    QFile schemeFile(newSchemeFileName);
    if (!schemeFile.open(QFile::WriteOnly | QFile::Truncate)) {
        qCWarning(DEBUG_KXMLGUI) << "Couldn't write to" << newSchemeFileName;
        return;
    }

    QDomDocument doc;
    QDomElement docElem = doc.createElement(QStringLiteral("gui"));
    doc.appendChild(docElem);
    QDomElement elem = doc.createElement(QStringLiteral("ActionProperties"));
    docElem.appendChild(elem);

    QTextStream out(&schemeFile);
    out << doc.toString(4);

    m_schemesList->addItem(newName);
    m_schemesList->setCurrentIndex(m_schemesList->findText(newName));
    updateDeleteButton();
    emit shortcutsSchemeChanged(newName);
}

void KShortcutSchemesEditor::deleteScheme()
{
    if (KMessageBox::questionYesNo(this,
                                   i18n("Do you really want to delete the scheme %1?\n\
Note that this will not remove any system wide shortcut schemes.", currentScheme())) == KMessageBox::No) {
        return;
    }

    //delete the scheme for the app itself
    QFile::remove(KShortcutSchemesHelper::writableApplicationShortcutSchemeFileName(currentScheme()));

    //delete all scheme files we can find for xmlguiclients in the user directories
    const auto dialogCollections = m_dialog->actionCollections();
    for (KActionCollection *collection : dialogCollections) {
        const KXMLGUIClient *client = collection->parentGUIClient();
        if (!client) {
            continue;
        }
        QFile::remove(KShortcutSchemesHelper::writableShortcutSchemeFileName(client->componentName(), currentScheme()));
    }

    m_schemesList->removeItem(m_schemesList->findText(currentScheme()));
    updateDeleteButton();
    emit shortcutsSchemeChanged(currentScheme());
}

QString KShortcutSchemesEditor::currentScheme()
{
    return m_schemesList->currentText();
}

void KShortcutSchemesEditor::exportShortcutsScheme()
{
    //ask user about dir
    QString path = QFileDialog::getSaveFileName(this, i18nc("@title:window", "Export Shortcuts"),
                                                QDir::currentPath(), i18n("Shortcuts (*.shortcuts)"));
    if (path.isEmpty()) {
        return;
    }

    m_dialog->exportConfiguration(path);
}

void KShortcutSchemesEditor::importShortcutsScheme()
{
    //ask user about dir
    QString path = QFileDialog::getOpenFileName(this, i18nc("@title:window", "Import Shortcuts"),
                                                QDir::currentPath(), i18n("Shortcuts (*.shortcuts)"));
    if (path.isEmpty()) {
        return;
    }

    m_dialog->importConfiguration(path);
}

void KShortcutSchemesEditor::saveAsDefaultsForScheme()
{
    if (KShortcutSchemesHelper::saveShortcutScheme(m_dialog->actionCollections(), currentScheme())) {
        KMessageBox::information(this, i18n("Shortcut scheme successfully saved."));
    } else {
        // We'd need to return to return more than a bool, to show more details here.
        KMessageBox::sorry(this, i18n("Error saving the shortcut scheme."));
    }
}

void KShortcutSchemesEditor::updateDeleteButton()
{
    m_deleteScheme->setEnabled(m_schemesList->count() >= 1);
}
