#ifndef HOUSE_H
#define HOUSE_H
#include "point.h"
#include <QPainter>
class rectangle
{
public:
    rectangle(){}
    rectangle(Point &a, Point &b, Point &c, Point &d);
    void show(QPainter &painter);
private:
    Point a,b,c,d;
};

class triangle{
public:
    triangle(){}
    triangle(Point &a,Point &b,Point &c);
    void show(QPainter &painter);
private:
    Point a,b,c;
};

/*class house(){
public:

};

Line(){}
Line(Point &a, Point &b);
float getLength();
Line(Line &l);
void show(QPainter & painter);
void setStart(Point &a);
void setEnd(Point &b);*/
#endif // HOUSE_H
