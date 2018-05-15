#include "person.h"
#include <QPainter>
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;
/*Line::Line(Point &a, Point &b):_pa(a),_pb(b){
    this->calLength();
}
QPainter.drawEllipse(Point &a,int lx,int ly);
float Line::getLength(){
    return this->_len;
}*/

oval::oval(Point &a, int lx, int ly):a(a),lx(lx),ly(ly){}
void oval::show(QPainter &painter){
    painter.drawEllipse(this->a.getX(),this->a.getY(),this->getlx(),this->getly());
    painter.drawLine(this->up1.getX(),this->up1.getY(),this->up.getX(),this->up.getY());
    painter.drawLine(this->up2.getX(),this->up2.getY(),this->up.getX(),this->up.getY());
    painter.drawLine(this->mid.getX(),this->mid.getY(),this->up.getX(),this->up.getY());
    painter.drawLine(this->mid.getX(),this->mid.getY(),this->down1.getX(),this->down1.getY());
    painter.drawLine(this->mid.getX(),this->mid.getY(),this->down2.getX(),this->down2.getY());
}

