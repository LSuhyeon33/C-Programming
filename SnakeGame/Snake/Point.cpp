#include <cmath>
#include <cstdlib>
#include "Point.h"

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int coordX, int coordY)
{
    x = coordX;
    y = coordY;
}

int Point::getX() const
{
    return x;
}
int Point::getY() const
{
    return y;
}
// mutator functions
void Point::setX(int coordX)
{
    x = coordX;
}
void Point::setY(int coordY)
{
    y = coordY;
}

bool Point::operator ==(const Point& point){
    return ((x == point.x) && (y == point.y));
}

Point& Point::operator =(const Point& point){
    this -> x = point.x;
    this -> y = point.y;
    return *this;
}