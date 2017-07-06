/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Defining the class 'Point' and its member functions.
*********************************************************************/

#include <iostream>
#include <string>
#include <math.h>       /* sqrt */
#include "Point.hpp"
using namespace std;
Point::Point()
{
    setXCoord(0);
    setYCoord(0);

}

Point::Point(double newX, double newY)
{
    setXCoord(newX);
    setYCoord(newY);

}

void Point::setXCoord(double newX)
{
    x = newX;
}
void Point::setYCoord(double newY)
{
    y = newY;
}
double Point::getXCoord ()const{
    return x;
};
double Point::getYCoord()const{
    return y;
};
double Point::distanceTo(const Point &nPoint){
    return sqrt(pow((nPoint.getXCoord()-x),2)+pow((nPoint.getYCoord()-y),2));
};