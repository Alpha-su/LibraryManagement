#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "line.h"
#include "point.h"
#include "house.h"
#include "person.h"
#include<QTime>
//#include <iostream>
//#include <string>
#include<QKeyEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setLine(Line l1,Line l2);
    void setrectangle(rectangle r);
    void settriangle(triangle t);
    void setoval(oval o);
    void keyPressEvent(QKeyEvent *);

protected slots:
    void movedLine();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
    Line line1;
    Line line2;
    Line line3;
    Line line4;
    Line line5;
    oval o;
    rectangle r;
    triangle t1;
    Line *belowLine1;
    Line *belowLine2;
    Line *belowLine3;
    Line *belowLine4;
    Line *belowLine5;
    oval *belowo;
    rectangle *belowrectangle;
    triangle *belowtriangle;
    QTimer *timer2;
};

#endif // MAINWINDOW_H
