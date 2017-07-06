/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/1/2017
** Description: A standard Deviation functions. Function works
but I got stuck iterating the pointers. The math works with regular 
arrays. 
*********************************************************************/

#include "Student.hpp"
#include <math.h>
double stdDev(student *arr, int size ){
    double total = 0.0, average=0, stdDeviation = 0;
    //calculate average
  //      cout<< "size:  "<<size<<endl;

 for(int  i=0; i<size; ++i)
    {    
        cout<<i<<endl;
        total = total + (arr)->getScore();
     //   cout<<"Name:  "<<arr[i].getName()<<endl;
      //  cout<<"scrore:  "<<arr[i].getScore()<<endl;
  arr++;
    }
  //  cout<< "total:  "<<total<<endl;
    average=total/size;
    //cout<< "average:  "<<average<<endl;

for(int i=0; i<size; ++i)
    stdDeviation+=pow(arr[i].getScore()-average,2);
    

    return sqrt(stdDeviation/size);
}
/*
int main(){
    
    student one("juan", 25.0);
    student two("jane", 89.0);
    student three("alex", 50.0);
    student *arr[3]={&one,&two,&three};

        cout<< "arr[0]:  "<< arr[0]->getName()<< " "<<arr[0]->getScore()<<endl;
        cout<< "arr[1]:  "<< arr[1]->getName()<< " "<<arr[1]->getScore()<<endl;
        cout<< "arr[2]:  "<< arr[2]->getName()<<" "<< arr[2]->getScore()<<endl;
   
    cout<< "stdDev(*arr,3):  "<< stdDev(*arr,3)<<endl;
    return 0;
}
*/