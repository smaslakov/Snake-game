#include "mainwindow.h"
#include "menuwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    MenuWindow* m;
    m = new MenuWindow(0,"");
    m->show();
    return a.exec();
}
