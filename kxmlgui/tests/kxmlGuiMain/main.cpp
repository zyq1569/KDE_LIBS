#include "mainwindow.h"
#include <klocalizedstring.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    KLocalizedString::setApplicationDomain("calligrawords");
    MainWindow w;
    w.show();
    return a.exec();
}
