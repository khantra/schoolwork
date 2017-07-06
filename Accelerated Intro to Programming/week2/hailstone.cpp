/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description: Write a function that counts how many steps it takes
for a hailstone sequence to reach one.
*********************************************************************/

#include <iostream>

using namespace std;
int Hailstone(int n)
{
/*********************************************************************
** Description: If the starting number is 1 it should return 0.
Otherwise check if prime by checking if the remainer is 0
when the number is divided by 2.
*********************************************************************/
    int count=0;
    if(n==1){
        return 0;
    }
    while(n!=1){
        count++;

    if(n % 2 == 0)
    {
        n /= 2;     //number is even
    }
    else
    {
        n = 3 * n + 1;  //number is odd

    }
    }
    return count;       //returns the value 
}
/*
int main()
{
    cout << Hailstone(4) << endl; 
   cout << Hailstone(3) << endl; 
   cout << Hailstone(5) << endl; 
   cout << Hailstone(7) << endl; 
   return 0;
}

*/