/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 1997 Nicolas Hadacek <hadacek@kde.org>
    SPDX-FileCopyrightText: 2001, 2001 Ellis Whitehead <ellis@kde.org>
    SPDX-FileCopyrightText: 2006 Hamish Rodda <rodda@kde.org>
    SPDX-FileCopyrightText: 2007 Roberto Raggi <roberto@kdevelop.org>
    SPDX-FileCopyrightText: 2007 Andreas Hartmetz <ahartmetz@gmail.com>
    SPDX-FileCopyrightText: 2008 Michael Jansen <kde@michael-jansen.biz>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KSHORTCUTSDIALOG_H
#define KSHORTCUTSDIALOG_H

#include <kxmlgui_export.h>

#include <QDialog>

#include "kshortcutseditor.h"

/**
 * @class KShortcutsDialog kshortcutsdialog.h KShortcutsDialog
 *
 * @short Dialog for configuration of KActionCollection and KGlobalAccel.
 *
 * The KShortcutsDialog class is used for configuring dictionaries of key/action
 * associations for KActionCollection and KGlobalAccel. It uses the KShortcutsEditor widget
 * and offers buttons to set all keys to defaults and invoke on-line help.
 *
 * Several static methods are supplied which provide the most convenient interface
 * to the dialog. The most common and most encouraged use is with KActionCollection.
 *
 * \code
 * KShortcutsDialog::configure( actionCollection() );
 * \endcode
 *
 * By default this dialog is modal (since 4.3). If you don't want that, setModal(false) and then the non-static
 * configure() will show the dialog. If you want to do anything extra when the dialog is done,
 * connect to okClicked() and/or cancelClicked(). However, if your extra stuff depends on the
 * changed settings already being saved, connect to saved() instead to be safe; if you connect to
 * okClicked() your function might be called before the save happens.
 *
 * Example:
 * \code
 * KShortcutsDialog dlg;
 * dlg.addCollection(myActions);
 * dlg.setModal(false);
 * connect(&dlg, SIGNAL(saved()), this, SLOT(doExtraStuff()));
 * dlg.configure();
 * \endcode
 *
 * \image html kshortcutsdialog.png "KShortcutsDialog"
 *
 * @author Nicolas Hadacek <hadacek@via.ecp.fr>
 * @author Hamish Rodda <rodda@kde.org> (KDE 4 porting)
 * @author Michael Jansen <kde@michael-jansen.biz>
 */
class KXMLGUI_EXPORT KShortcutsDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * Constructs a KShortcutsDialog as a child of @p parent.
     * Set @p allowLetterShortcuts to false if unmodified alphanumeric
     * keys ('A', '1', etc.) are not permissible shortcuts.
     */
    explicit KShortcutsDialog(KShortcutsEditor::ActionTypes types = KShortcutsEditor::AllActions,
                              KShortcutsEditor::LetterShortcuts allowLetterShortcuts = KShortcutsEditor::LetterShortcutsAllowed,
                              QWidget *parent = nullptr);

    /**
     * Destructor. Deletes all resources used by a KShortcutsDialog object.
     */
    ~KShortcutsDialog() override;

    /**
     * Add all actions of the collection to the ones displayed and configured
     * by the dialog.
     *
     * @param title the title associated with the collection (if null, the
     * KAboutData::progName() of the collection's componentData is used)
     */
    void addCollection(KActionCollection *, const QString &title = QString());

    /**
     * @return the list of action collections that are available for configuration in the dialog.
     */
    QList<KActionCollection *> actionCollections() const;

    /**
     * Run the dialog and call writeSettings() on the action collections
     * that were added if @p saveSettings is true.
     */
    bool configure(bool saveSettings = true);

    /** @see QWidget::sizeHint() */
    QSize sizeHint() const override;

    /**
     * Pops up a modal dialog for configuring key settings. The new
     * shortcut settings will become active if the user presses OK.
     *
     * @param collection the KActionCollection to configure
     * @param allowLetterShortcuts set to KShortcutsEditor::LetterShortcutsDisallowed if unmodified alphanumeric
     *  keys ('A', '1', etc.) are not permissible shortcuts.
     * @param parent the parent widget to attach to
     * @param bSaveSettings if true, the settings will also be saved back
     * by calling writeSettings() on the action collections that were added.
     *
     * @return Accept if the dialog was closed with OK, Reject otherwise.
     */
    static int configure(KActionCollection *collection, KShortcutsEditor::LetterShortcuts allowLetterShortcuts =
                             KShortcutsEditor::LetterShortcutsAllowed, QWidget *parent = nullptr, bool bSaveSettings = true);

    /**
     * Imports a shortcuts set up from @p path
     *
     * @since 5.15
     */
    void importConfiguration(const QString &path);

    /**
     * Exports a shortcuts set up from @p path
     *
     * @since 5.15
     */
    void exportConfiguration(const QString &path) const;

public Q_SLOTS:
    /**
     * @reimp
     */
    void accept() override;

Q_SIGNALS:
    /**
     * emitted after ok is clicked and settings are saved
     */
    void saved();

private:
    Q_PRIVATE_SLOT(d, void changeShortcutScheme(const QString &))
    Q_PRIVATE_SLOT(d, void toggleDetails())

    class KShortcutsDialogPrivate;
    friend class KShortcutsDialogPrivate;
    class KShortcutsDialogPrivate *const d;

    Q_DISABLE_COPY(KShortcutsDialog)
};

#endif // KSHORTCUTSDIALOG_H

