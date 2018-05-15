#ifndef POINT_H
#define POINT_H


class Point{
public :
    Point(float xx = 0, float yy = 0) {
            _x = xx;
            _y = yy;
    }
    Point(Point &p);

    bool pong();
    float getX();
    float getY();
    void setX(float x);
    void setY(float y);
private:
    float _x;
    float _y;
};

#endif // POINT_H
