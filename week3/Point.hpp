/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Declaring the class 'Point' and its member functions.
*********************************************************************/


#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

using namespace std;

class Point{
private:
double x;
double y;

public:
Point();
Point(double,double);
void setXCoord(double);
void setYCoord(double);
/*********************************************************************
** Description: Passing constant reference to ensure values are protected.
distinguidish accessors as constants so they can access these Values in 'distanceTo()'.
** "It can only call accessor functions that have themselves been designated
as constant functions. EX: 'double getPrice() const {}'"
*********************************************************************/
double getXCoord()const;
double getYCoord()const;
double distanceTo(const Point &nPoint);
};
#endif
