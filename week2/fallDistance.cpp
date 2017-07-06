/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description:A function that calculates the fall distance.
*********************************************************************/
#include <iostream>

using namespace std;
float  fallDistance (float time){
    return (9.8*(time*time))/2;
}
/*
int main()
{
    float time=3.0;

  cout<<   fallDistance ( time)<<endl;
   
   return 0;
}
*/