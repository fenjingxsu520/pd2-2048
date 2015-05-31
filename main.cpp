#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //QPushButton *restart = new QPushButton("restart");
    //QPushButton *restart = new QPushButton("restart");
       //QObject::connect(restart, SIGNAL(clicked()),
                        //&a,SLOT(quit()));

    //Qwidget  setFocus();  setFocusPolicy(Tab..)

    return a.exec();
}
