/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2008 Rafael Fernández López <ereslibre@kde.org>

    SPDX-License-Identifier: LGPL-2.0-only
*/

#include <QAction>
#include <QTextEdit>
#include <QTimer>
#include <QApplication>
#include <QStandardPaths>
#include <QTest>

#include <kxmlguiwindow.h>
#include <kactioncollection.h>
#include <kmessagebox.h>
#include <kconfiggroup.h>

// BUG: if this symbol is defined the problem consists on:
//      - main window is created.
//      - settings are saved (and applied), but in this case no toolbars exist yet, so they don't
//        apply to any toolbar.
//      - after 1 second the GUI is created.
//
//      How to reproduce ?
//          - Move one toolbar to other place (bottom, left, right, or deattach it).
//          - Close the test (so settings are saved).
//          - Reopen the test. The toolbar you moved is not keeping the place you specified.
#define REPRODUCE_TOOLBAR_BUG

class MainWindow: public KXmlGuiWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

public Q_SLOTS:
    void slotTest();
    void slotCreate();

private:
    void setupActions();
};
