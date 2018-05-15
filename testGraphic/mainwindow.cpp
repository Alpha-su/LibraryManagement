#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "line.h"
#include <QTimer>
#include <stdio.h>
#include <QMessageBox>
#include <string>
#include "house.h"
#include "person.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(movedLine()));//timeoutslot()为自定义槽
    timer2->start(2);
    //Point p1(200,40), p2(300,30);
    //this->belowLine1 = new  Line(p1, p2);
    Point p3(400,400),p4(800,400),p5(800,800),p6(400,800);
    this->belowrectangle = new rectangle(p3,p4,p5,p6);
    Point p7(300,400),p8(600,100),p9(900,400);
    this->belowtriangle = new triangle(p7,p8,p9);
    Point sp1(980,600),sp2(1000,650),sp3(950,690),sp4(1050,690),sp5(1000,735),
            sp6(950,800),sp7(1050,800);
   // int lx = 40,ly = 50;
    this->belowLine1 = new  Line(sp2, sp3);
    this->belowLine2 = new  Line(sp2, sp4);
    this->belowLine3 = new  Line(sp2, sp5);
    this->belowLine4 = new  Line(sp5, sp6);
    this->belowLine5 = new  Line(sp5, sp7);
    this->belowo = new  oval(sp1,40,50);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer2;
}

void MainWindow::setLine(Line l1,Line l2){
    this->line1 = l1;
    this->line2 = l2;
}

void MainWindow::setrectangle(rectangle r){
    this->r = r;
}

void MainWindow::settriangle(triangle t){
    this->t1 = t;
}
void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(QPen(Qt::blue,4));//设置画笔形式
    painter.drawPixmap(rect(), QPixmap("://images/image.jpg"));
   // this->belowLine1->show(painter);
    //this->belowLine2->show(painter);
    this->belowLine3->show(painter);
    this->belowLine4->show(painter);
    this->belowLine5->show(painter);
    this->belowo->show(painter);
    this->belowrectangle->show(painter);
    this->belowtriangle->show(painter);
    this->line1.show(painter);
    this->line2.show(painter);
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    static int ai=40;
    static int bi=60;

    if(e->key() == Qt::Key_Z)
    {
        //        QMessageBox::about(NULL, "You Press Key", "<font color='red'>Key Z </font>");
        bi = bi + 5;
        ai = ai + 5;
        Point a(100, ai);
        Point b(100, bi);
        this->belowLine1->setStart(a);
        this->belowLine1->setEnd(b);
    }
    else
    {
        //        QMessageBox::about(NULL, "You Press Key", "<font color='red'>Key </font>"+ QString::number(e->key(),10));
        bi = bi - 5;
        ai = ai - 5;
        Point a(100, ai);
        Point b(100, bi);
        this->belowLine1->setStart(a);
        this->belowLine1->setEnd(b);
    }
}


void MainWindow::movedLine()
{
    static int i = 950;
    static int j = 690;
    //static int i1,j1;
    //i1 = i
    i = i - 1;
    j = j - 1;
    Point p1(i,j), sp2(1000,650), p2(i + 100 , j);

    if (p1.pong()==false)
    {
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        //i = rand()%30+920;
        //j=rand()%30+660;
        i=950;
        j=690;
             //QMessageBox::about(NULL, "alert", "<font color='red'>go out </font>" + QString::number(i,10));
        p1.setX(i);
        p1.setY(j);
        p2.setX(i);
        p2.setY(j);
        sp2.setX(1000);
        sp2.setY(650);
    }

    Line l1(p1,sp2);
    Line l2(p2,sp2);
    this->setLine(l1,l2);
    //this->setLine(l2);
    this->repaint();
}
