#ifndef PERSON_H
#define PERSON_H
#include<QPainter>
#include<line.h>
class oval{
public:
    oval(){}
    oval(Point &a, int lx, int ly);
    void show(QPainter &painter);
    int getlx(){
        return lx;
    }
    int getly(){
        return ly;
    }

private:
    Point a;
    Point up,up1,up2,mid,down1,down2;
    int lx,ly;
};
/*Line(){}
Line(Point &a, Point &b);
float getLength();
Line(Line &l);
void show(QPainter & painter);
void setStart(Point &a);
void Line::show(QPainter & painter){
    painter.drawLine(this->_pa.getX(),this->_pa.getY(),this->_pb.getX(),this->_pb.getY());
}
void setEnd(Point &b);*/
#endif // PERSON_H
