#include "mainwindow.h"
#include <QApplication>
#include <QPainter>
#include "line.h"
#include "point.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


//    Point p1(30,458), p2(20,700);
//    Line l(p1,p2);
//    w.setLine(l);
    w.show();
    //w.movedLine();


    return a.exec();
}
