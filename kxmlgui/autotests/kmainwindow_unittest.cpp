/*
    This file is part of the KDE libraries
    SPDX-FileCopyrightText: 2006 David Faure <faure@kde.org>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#include "kmainwindow_unittest.h"

#include <QTest>
#include <QEventLoopLocker>
#include <kmainwindow.h>
#include <QStatusBar>
#include <QResizeEvent>
#include <ktoolbar.h>
#include <ksharedconfig.h>
#include <kconfiggroup.h>

QTEST_MAIN(KMainWindow_UnitTest)

void KMainWindow_UnitTest::initTestCase()
{
    QStandardPaths::setTestModeEnabled(true);
    QFile::remove(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + QLatin1Char('/') + KSharedConfig::openConfig()->name());
}

void KMainWindow_UnitTest::cleanupTestCase()
{
    QFile::remove(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation) + QLatin1Char('/') + KSharedConfig::openConfig()->name());
}

void KMainWindow_UnitTest::testDefaultName()
{
    KMainWindow mw;
    mw.show();
    mw.ensurePolished();
    QCOMPARE(mw.objectName(), QStringLiteral("MainWindow#1"));
    KMainWindow mw2;
    mw2.show();
    mw2.ensurePolished();
    QCOMPARE(mw2.objectName(), QStringLiteral("MainWindow#2"));
}

void KMainWindow_UnitTest::testFixedName()
{
    KMainWindow mw;
    mw.setObjectName(QStringLiteral("mymainwindow"));
    mw.show();
    mw.ensurePolished();
    QCOMPARE(mw.objectName(), QStringLiteral("mymainwindow"));
    KMainWindow mw2;
    mw2.setObjectName(QStringLiteral("mymainwindow"));
    mw2.show();
    mw2.ensurePolished();
    QCOMPARE(mw2.objectName(), QStringLiteral("mymainwindow2"));
}

void KMainWindow_UnitTest::testNameWithHash()
{
    KMainWindow mw;
    mw.setObjectName(QStringLiteral("composer#"));
    mw.show();
    mw.ensurePolished();
    QCOMPARE(mw.objectName(), QStringLiteral("composer#1"));
    KMainWindow mw2;
    mw2.setObjectName(QStringLiteral("composer#"));
    mw2.show();
    mw2.ensurePolished();
    QCOMPARE(mw2.objectName(), QStringLiteral("composer#2"));
    KMainWindow mw4;
    mw4.setObjectName(QStringLiteral("composer#4"));
    mw4.show();
    mw4.ensurePolished();
    QCOMPARE(mw4.objectName(), QStringLiteral("composer#4"));
}

void KMainWindow_UnitTest::testNameWithSpecialChars()
{
    KMainWindow mw;
    mw.setObjectName(QStringLiteral("a#@_test/"));
    mw.show();
    mw.ensurePolished();
    QCOMPARE(mw.dbusName(), QStringLiteral("/kmainwindow_unittest/a___test_"));
    KMainWindow mw2;
    mw2.setObjectName(QStringLiteral("a#@_test/"));
    mw2.show();
    mw2.ensurePolished();
    QCOMPARE(mw2.dbusName(), QStringLiteral("/kmainwindow_unittest/a___test_2"));
}

static bool s_mainWindowDeleted;
class MyMainWindow : public KMainWindow
{
public:
    MyMainWindow() : KMainWindow(),
        m_queryClosedCalled(false)
    {
    }
    bool queryClose() override
    {
        m_queryClosedCalled = true;
        return true;
    }
    ~MyMainWindow()
    {
        s_mainWindowDeleted = true;
    }
    bool m_queryClosedCalled;

    void reallyResize(int width, int height)
    {
        const QSize oldSize = size();

        resize(width, height);

        // Send the pending resize event (resize() only sets Qt::WA_PendingResizeEvent)
        QResizeEvent e(size(), oldSize);
        QApplication::sendEvent(this, &e);

        QCOMPARE(this->width(), width);
        QCOMPARE(this->height(), height);
    }
};

// Here we test
// - that queryClose is called
// - that autodeletion happens
void KMainWindow_UnitTest::testDeleteOnClose()
{
    QEventLoopLocker locker; // don't let the deref in KMainWindow quit the app.
    s_mainWindowDeleted = false;
    MyMainWindow *mw = new MyMainWindow;
    QVERIFY(mw->testAttribute(Qt::WA_DeleteOnClose));
    mw->close();
    QVERIFY(mw->m_queryClosedCalled);
    qApp->sendPostedEvents(mw, QEvent::DeferredDelete);
    QVERIFY(s_mainWindowDeleted);
}

void KMainWindow_UnitTest::testSaveWindowSize()
{
    QCOMPARE(KSharedConfig::openConfig()->name(), QStringLiteral("kmainwindow_unittestrc"));
    KConfigGroup cfg(KSharedConfig::openConfig(), "TestWindowSize");

    {
        MyMainWindow mw;
        mw.show();
        KToolBar *tb = new KToolBar(&mw); // we need a toolbar to trigger an old bug in saveMainWindowSettings
        tb->setObjectName(QStringLiteral("testtb"));
        mw.reallyResize(800, 600);
        QTRY_COMPARE(mw.size(), QSize(800, 600));
        QTRY_COMPARE(mw.windowHandle()->size(), QSize(800, 600));
        mw.saveMainWindowSettings(cfg);
        mw.close();
    }

    KMainWindow mw2;
    mw2.show();
    KToolBar *tb = new KToolBar(&mw2);
    tb->setObjectName(QStringLiteral("testtb"));
    mw2.resize(500, 500);
    mw2.applyMainWindowSettings(cfg);

    QTRY_COMPARE(mw2.size(), QSize(800, 600));
}

void KMainWindow_UnitTest::testAutoSaveSettings()
{
    const QString group(QStringLiteral("AutoSaveTestGroup"));

    {
        MyMainWindow mw;
        mw.show();
        KToolBar *tb = new KToolBar(&mw); // we need a toolbar to trigger an old bug in saveMainWindowSettings
        tb->setObjectName(QStringLiteral("testtb"));
        mw.setAutoSaveSettings(group);
        mw.reallyResize(800, 600);
        mw.close();
    }

    KMainWindow mw2;
    mw2.show();
    KToolBar *tb = new KToolBar(&mw2);
    tb->setObjectName(QStringLiteral("testtb"));
    mw2.setAutoSaveSettings(group);
    QTRY_COMPARE(mw2.size(), QSize(800, 600));
}

void KMainWindow_UnitTest::testNoAutoSave()
{
    const QString group(QStringLiteral("AutoSaveTestGroup"));

    {
        // A mainwindow with autosaving, but not of the window size.
        MyMainWindow mw;
        mw.show();
        mw.setAutoSaveSettings(group, false);
        mw.reallyResize(750, 550);
        mw.close();
    }

    KMainWindow mw2;
    mw2.show();
    mw2.setAutoSaveSettings(group, false);
    // NOT 750, 550! (the 800,600 comes from testAutoSaveSettings)
    QTRY_COMPARE(mw2.size(), QSize(800, 600));
}

void KMainWindow_UnitTest::testWidgetWithStatusBar()
{
    // KMainWindow::statusBar() should not find any indirect QStatusBar child
    // (e.g. in a case like konqueror, with one statusbar per frame)
    MyMainWindow mw;
    QWidget *frame1 = new QWidget(&mw);
    QStatusBar *frameStatusBar = new QStatusBar(frame1);
    QVERIFY(mw.statusBar() != frameStatusBar);
}
