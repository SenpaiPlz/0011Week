#include "UI/mainwindow.h"
#include "UI/logobox.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    LogoBox box;
    box.show();

    return a.exec();
}
