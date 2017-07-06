/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Declaring the class 'Box' and its member functions.
*********************************************************************/

#ifndef Box_HPP
#define BOX_HPP

#include <iostream>

class Box
{
private:
    double  width;
    double  height;
    double  length;

public:
    Box();
    Box(double , double , double );
    
    void setHeight(double);
    void setWidth(double);
    void setLength(double);

    double getVolume();
    double getSurfaceArea();


};

#endif