/*********************************************************************
** Author: Khandakar Shadid
** Date: 1/12/2017
** Description: Convert Celsius to Farenehit
*********************************************************************/


#include <iostream>
using namespace std;

int main()
{
	float celsiusTemp=0;
	cout << "Please enter a Celsius temperature." << endl; 
	cin>>celsiusTemp;
	cout << "The equivalent Fahrenheit temperature is:" << endl; 
cout << (1.8*celsiusTemp)+32 << endl; 

	return 0;
}

