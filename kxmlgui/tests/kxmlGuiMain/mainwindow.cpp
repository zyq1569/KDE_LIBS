#include "mainwindow.h"

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
}

MainWindow::~MainWindow()
{

}

