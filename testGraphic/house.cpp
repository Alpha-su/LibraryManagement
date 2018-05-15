#include "house.h"
#include <QPainter>
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;
rectangle::rectangle(Point &a, Point &b, Point &c, Point &d):a(a),b(b),c(c),d(d){}
void rectangle::show(QPainter &painter){
      painter.drawLine(this->a.getX(),this->a.getY(),this->b.getX(),this->b.getY());
      painter.drawLine(this->b.getX(),this->b.getY(),this->c.getX(),this->c.getY());
      painter.drawLine(this->c.getX(),this->c.getY(),this->d.getX(),this->d.getY());
      painter.drawLine(this->d.getX(),this->d.getY(),this->a.getX(),this->a.getY());
}

triangle::triangle(Point &a, Point &b, Point &c):a(a),b(b),c(c){}
void triangle::show(QPainter &painter){
    painter.drawLine(this->a.getX(),this->a.getY(),this->b.getX(),this->b.getY());
    painter.drawLine(this->b.getX(),this->b.getY(),this->c.getX(),this->c.getY());
    painter.drawLine(this->c.getX(),this->c.getY(),this->a.getX(),this->a.getY());
}
