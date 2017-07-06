/*********************************************************************
** Author: Khandakar Shadid
** Date: 1/12/2017
** Description:A program that asks the user for a (integer) number of cents, from 0 to 99,
and outputs how many of each type of coin would represent that amount with the fewest total number of coins.
*********************************************************************/

#include <iostream>
#include <string>

using namespace std;
    int input=0;

int main()
{

    
    cout << "Please enter an amount in cents less than a dollar." << endl; 
    cin >>input;
    cout<< "Your change Will be:"<<endl;

    int quarterVal=25;
    cout<<"Q:"<< (input/quarterVal)<<endl;
    input= input-((input/quarterVal) * quarterVal);
	int dimeVal=10;
    cout<<"D:"<< (input/dimeVal)<<endl;
    input= input-((input/dimeVal) * dimeVal);
    int nickleVal=5;
    cout<<"N:"<< (input/nickleVal)<<endl;;
    input= input-((input/nickleVal) * nickleVal);
    int pennyVal=1;
    cout<<"p:"<< (input/pennyVal)<<endl;;
    input= input-((input/pennyVal) * pennyVal);




   return 0;
}
