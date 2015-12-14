#include "UI/mainwindow.h"
#include <QApplication>
#include "UI/logobox.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LogoBox logo;
    logo.show();

    return a.exec();
}
