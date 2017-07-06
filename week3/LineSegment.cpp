/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Defining the class 'LineSegment' and its member functions.
*********************************************************************/

#include <iostream>
#include <string>
#include <math.h>       /* sqrt */
#include "LineSegment.hpp"

using namespace std;

LineSegment::LineSegment()
{
    startPoint;
    endPoint;
}

LineSegment::LineSegment(Point newstartPoint, Point newendPoint)
{
    setstartPoint( newstartPoint);
    setendPoint( newendPoint);
}

void LineSegment::setstartPoint(Point newPoint)
{
    startPoint = newPoint;
}
void LineSegment::setendPoint(Point newPoint)
{
    endPoint = newPoint;
}
Point LineSegment::getstartPoint(){
    return startPoint;
};
Point LineSegment::getendPoint(){
    return endPoint;
};

/*********************************************************************
** Description: Find use the member function of the class Point called distanceTo 
** which uses the distance formula to calculate length. 
** Then use the slope formula and accessors to calculate slope.
*********************************************************************/
double LineSegment::length(){
    return startPoint.distanceTo(endPoint);
};

double LineSegment::slope(){
    return ((endPoint.getYCoord()-startPoint.getYCoord())/(endPoint.getXCoord()-startPoint.getXCoord()) );
};