#ifndef LINE_H
#define LINE_H
#include "point.h"
#include <QPainter>
class Line{
public:
    Line(){}
    Line(Point &a, Point &b);
    float getLength();
    Line(Line &l);
    void show(QPainter & painter);
    void setStart(Point &a);
    void setEnd(Point &b);

private:
    void calLength();//计算线段长度，并保存到属性 _len 中
    Point _pa, _pb;
    float _len;
};

#endif // LINE_H
