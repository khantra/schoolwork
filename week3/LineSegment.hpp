/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Declaring the class 'LineSegment' and its member functions.
*********************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP


#include "Point.hpp"
// Defines the interface of the Movie class
class LineSegment
{
private:
    Point startPoint;
    Point endPoint;
public:
    LineSegment();
    LineSegment(Point,Point);
    void setstartPoint(Point);
    void setendPoint(Point);
    Point getstartPoint();
    Point getendPoint();
    double length();
    double slope();
};
#endif