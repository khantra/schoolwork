/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/15/2017
** Description:/  a recursive function named summer that takes two
 parameters - an array of doubles and the size of the array - and returns
 the sum of the values in the array.   
*********************************************************************/


#include <iostream>

using namespace std;
double summer( double arr[], int size )
{
  if ( size == 0 ){  // if 0 then we have reached the end (or in this case the start of the array)
    return 0 ; 
    }
  else
    {
       // cout<<size<<" "<< summer( arr, size - 1 ) <<endl;
          double sum=0; 
          sum= summer( arr, size - 1 ) ; // everytime is
          return sum + arr[size-1  ] ;
        /*
      
        cout<<size<<" "<< sum<< " "<< arr[size- 1 ]<<endl;
       
        cout<<">"<<size<<" "<< sum<< " "<< arr[size- 1 ]<<endl;
        */
    }
}


int main()
{
     double arr[8]={0.5,0.5,0.5,0.5,1.0,1.0,2.0,4.5};	
   cout << summer( arr, 8 ) << endl;    
   return 0;
}


