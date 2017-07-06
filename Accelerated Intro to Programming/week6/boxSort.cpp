/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/8/2017
** Description:/ Sorting an array of "Box" objects using a bubble sort.
**************** To do so I just had to edit the bubble sort to accept 
**************** a Box object. I then tested it using random numbers. 
*********************************************************************/
#include <iostream>
using namespace std;
#include "Box.hpp"
/*
#include <stdlib.h>     
#include <time.h>       
*/
void boxSort(Box array[], int size){
Box temp;
bool swap;

do{ 
	swap = false;
	for (int count = 0; count < (size - 1); count++){
		if (array[count].getVolume() < array[count + 1].getVolume()){
			temp = array[count];
			array[count] = array[count + 1]; 
			array[count + 1] = temp;
			swap = true;
			}
	}
 } while (swap); // Loop again if a swap occurred on this pass.
}
/*
void showArray(Box array[], int size){
for (int count = 0; count < size; count++)
cout <<"Box No."<<count <<" "<< array[count].getVolume() << " "<< endl;
}


int main()
{
Box box1(2.4, 7.1, 5.0);
Box box2 (4,5,5);
double volume1 = box1.getVolume();
double surfaceArea1 = box1.getSurfaceArea();
double volume2 = box2.getVolume();
double surfaceArea2 = box2.getSurfaceArea();
cout<<"volume1= "<<volume1<<"surfaceArea1= "<<surfaceArea1<<"volume2= "<<volume2<<"surfaceArea2= "<<surfaceArea2<<endl;
Box arr[20];
 srand (time(NULL));
for(int i=0; i<20;i++){
    double h=(i+1)*(rand() % 3) + 12, w=(i+1)*(rand() % 2) + 6,l=(i+1)*(rand() % 3) +7;
    arr[i].setHeight(h);
    arr[i].setWidth(w);
    arr[i].setLength(l);
    //cout<<"Box No."<<i <<" "<< " L: "<< l<< " W:"<< w<<" H:"<<h<<" volume: "<<arr[i].getVolume()<<endl;
}
showArray(arr, 20);
boxSort(arr, 20);
cout<<"Now Sorted:"<<endl;
showArray(arr, 20);
}
*/