/********************************************************************************
** Form generated from reading UI file 'kshortcutsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KSHORTCUTSDIALOG_H
#define UI_KSHORTCUTSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ktreewidgetsearchlinewidget.h"

QT_BEGIN_NAMESPACE

class Ui_KShortcutsDialog
{
public:
    QVBoxLayout *verticalLayout;
    KTreeWidgetSearchLineWidget *searchFilter;
    QTreeWidget *list;

    void setupUi(QWidget *KShortcutsDialog)
    {
        if (KShortcutsDialog->objectName().isEmpty())
            KShortcutsDialog->setObjectName(QString::fromUtf8("KShortcutsDialog"));
        KShortcutsDialog->resize(761, 549);
        verticalLayout = new QVBoxLayout(KShortcutsDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchFilter = new KTreeWidgetSearchLineWidget(KShortcutsDialog);
        searchFilter->setObjectName(QString::fromUtf8("searchFilter"));

        verticalLayout->addWidget(searchFilter);

        list = new QTreeWidget(KShortcutsDialog);
        list->setObjectName(QString::fromUtf8("list"));
        list->setRootIsDecorated(true);
        list->setSortingEnabled(true);

        verticalLayout->addWidget(list);


        retranslateUi(KShortcutsDialog);

        QMetaObject::connectSlotsByName(KShortcutsDialog);
    } // setupUi

    void retranslateUi(QWidget *KShortcutsDialog)
    {
#if QT_CONFIG(whatsthis)
        searchFilter->setWhatsThis(QCoreApplication::translate("KShortcutsDialog", "Search interactively for shortcut names (e.g. Copy) or combination of keys (e.g. Ctrl+C) by typing them here.", nullptr));
#endif // QT_CONFIG(whatsthis)
        QTreeWidgetItem *___qtreewidgetitem = list->headerItem();
        ___qtreewidgetitem->setText(6, QCoreApplication::translate("KShortcutsDialog", "Mouse Shape Gesture", nullptr));
        ___qtreewidgetitem->setText(5, QCoreApplication::translate("KShortcutsDialog", "Mouse Button Gesture", nullptr));
        ___qtreewidgetitem->setText(4, QCoreApplication::translate("KShortcutsDialog", "Global Alternate", nullptr));
        ___qtreewidgetitem->setText(3, QCoreApplication::translate("KShortcutsDialog", "Global", nullptr));
        ___qtreewidgetitem->setText(2, QCoreApplication::translate("KShortcutsDialog", "Alternate", nullptr));
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("KShortcutsDialog", "Shortcut", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("KShortcutsDialog", "Action", nullptr));
#if QT_CONFIG(whatsthis)
        list->setWhatsThis(QCoreApplication::translate("KShortcutsDialog", "Here you can see a list of key bindings, i.e. associations between actions (e.g. 'Copy') shown in the left column and keys or combination of keys (e.g. Ctrl+V) shown in the right column.", nullptr));
#endif // QT_CONFIG(whatsthis)
        (void)KShortcutsDialog;
    } // retranslateUi

};

namespace Ui {
    class KShortcutsDialog: public Ui_KShortcutsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KSHORTCUTSDIALOG_H
