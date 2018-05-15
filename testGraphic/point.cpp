#include "point.h"
#include <cmath>
#include<algorithm>
#include<iostream>
using namespace std;

Point::Point(Point &p) {	//复制构造函数的实现
    _x = p._x;
    _y = p._y;
    //cout<< "Calling the copy constructor of Point"<<this->getX()<<","<<this->getY()<< endl;
}


float Point::getX(){
    return this->_x;
}
float Point::getY(){
    return this->_y;
}

void Point::setX(float x){
    _x = x ;
}

void Point::setY(float y){
    _y = y;
}

bool Point::pong(){
    if(_x > 920 || _y> 660)
        return true;
    return false;
}
