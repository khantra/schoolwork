/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Defining the class 'Box' and its member functions.
*********************************************************************/

#include <iostream>

using namespace std;
#include "Box.hpp"

Box::Box()
{

    setHeight(1);
    setWidth(1);
    setLength(1);
}

Box::Box(double height, double width, double length)
{
    setHeight(height);
    setWidth(width);
    setLength(length);
}

void Box::setHeight(double newHeight)
{
    height = newHeight;
}

void Box::setWidth(double newWidth)
{
    width = newWidth;
}

void Box::setLength(double newLength)
{
    length = newLength;
}


double Box::getVolume()
{
    return length*width*height;
}

double Box::getSurfaceArea()
{
    return (2*(length*width))+(2*(height*length))+(2*(height*width));
}



