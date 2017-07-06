/*********************************************************************
** Author: Khandakar Shadid
** Date: 1/12/2017
** Description:A program that asks the user for five numbers and then prints out the average of those numbers.  
*********************************************************************/

#include<iostream>

using namespace std;

int main()
{
	cout<<"Please enter five numbers."<<endl;
	float input=0, average=0, temp=0, count=0;
	cin>>input;
	count=count+1;
	temp+=input;

	cin>>input;
	count=count+1;
	temp+=input;

	cin>>input;
	count=count+1;
	temp+=input;

	cin>>input;
	count=count+1;
	temp+=input;

	cin>>input;
	count=count+1;
	temp+=input;
	
	cout << "The average of those numbers is:"<<endl; 
	cout<<temp/count<<endl;
   return 0;
}

