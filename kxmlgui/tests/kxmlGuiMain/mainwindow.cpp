#include "mainwindow.h"
#include "kswitchlanguagedialog.h"

//#include <QAction>
//#include <QTextEdit>
//#include <QApplication>
using namespace KDEPrivate;
MainWindow::MainWindow(QWidget *parent)
//    : QMainWindow(parent)
    : KXmlGuiWindow(parent)
{
    setXMLFile(QFINDTESTDATA("kxmlGuiMain.rc"), true);

    // Because we use a full path in setXMLFile, we need to call setLocalXMLFile too.
    // In your apps, just pass a relative filename to setXMLFile instead.
    setLocalXMLFile(QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation) + QLatin1Char('/') +
                    QStringLiteral("kxmlGuiMain/kxmlGuiMain.rc"));

    //setCentralWidget(new QTextEdit(this));
    setupActions();
}

void MainWindow::slotTest()
{
    KMessageBox::information(nullptr, QStringLiteral("--Test--"), QStringLiteral("caption"));

    static KSwitchLanguageDialog * dialog =  new KSwitchLanguageDialog(this);
    if (dialog)
    {
        dialog->show();
    }
}

void MainWindow::slotCreate()
{
    //setStandardToolBarMenuEnabled(true);
    setupGUI(ToolBar|Keys);
    //setupGUI(ToolBar | Keys |  Save );
    createGUI(xmlFile());

//    if (autoSaveConfigGroup().isValid())
//    {
//        applyMainWindowSettings(autoSaveConfigGroup());
//    }
}

void MainWindow::setupActions()
{
    QAction *testAction = new QAction(this);
    testAction->setText(QStringLiteral("TestWindow"));
    //testAction->setIcon(QIcon::fromTheme(QStringLiteral("kde")));
    actionCollection()->addAction(QStringLiteral("test"), testAction);
    connect(testAction, SIGNAL(triggered(bool)), this, SLOT(slotTest()));

    KStandardAction::quit(qApp, SLOT(quit()), actionCollection());

    setAutoSaveSettings();

//    // BUG: if the GUI is created after an amount of time (so settings have been saved), then toolbars
//    //      are shown misplaced. KMainWindow uses a 500 ms timer to save window settings.
#ifdef REPRODUCE_TOOLBAR_BUG
    QTimer::singleShot(1000, this, SLOT(slotCreate())); // more than 500 ms so the main window has saved settings.
    // We can think of this case on natural applications when they
    // load plugins and change parts. It can take 1 second perfectly.
#else
    QTimer::singleShot(0, this, SLOT(slotCreate()));
#endif
}

MainWindow::~MainWindow()
{

}







