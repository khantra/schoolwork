/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description:A program that asks the user how many integers they would like to enter,
and then finds the minimum and maximum value without using an array.
*********************************************************************/

#include <iostream>

using namespace std;

int main()
{
	
/*********************************************************************
** Description:
**Prompt User for How Many Integers They'd like to enter, followed by a 
prompt asking to enter that many numbers using a 'for' loop. 
*********************************************************************/
    int userInput=0, totalNumber=0, minValue=0, maxValue=0;
   cout << "How many integers would you like to enter?" << endl; 
   cin>>userInput;
   totalNumber=userInput;
   cout<<"Enter "<< totalNumber<<" Numbers"<<endl;
   
   for(int count=0;count<totalNumber;count++){
       int currentNumber=0;
       cin>>currentNumber;
/*********************************************************************
** Description:
**We only care about the min and max value so we set them to the current number 
before comparing them each with every number that comes after. If the current Min
value is less than the current number inputed by the user then they are overwritten 
by the lesser value,the reverse is true for the max. So if current number is 
greater the maxvalue it overwrites it.
*********************************************************************/
       if(count==0){
           minValue=currentNumber;
           maxValue=currentNumber;
       }
       if(currentNumber <minValue){
           minValue=currentNumber;
       }
       else if(currentNumber >maxValue){
           maxValue=currentNumber;
       }
       
   }
   
/*********************************************************************
** Description:
**Output min and max.
*********************************************************************/   
   cout<<"minValue:"<<minValue<<endl<<"maxValue:"<<maxValue<<endl;
   
   return 0;
}

