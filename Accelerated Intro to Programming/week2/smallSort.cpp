/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description:A void function named smallSort that takes three int 
parameters by reference and then sorts them from least to greatest.
*********************************************************************/
#include <iostream>

using namespace std;
void  smallSort (int &a,int &b,int &c){

/*********************************************************************
** Description: Compare each of the numbers against each other and 
swap them approrpriately so they are arranged least to greatest.
*********************************************************************/
if(a>c){
     int tmp=a;
    a=c;
    c=tmp;
    }

    if(a>b){
    int tmp=a;
    a=b;
    b=tmp;
    }
    if(b>c){
    int tmp=b;
    c=b;
    c=tmp;
    }

}
/*
int main()
{
    int a = 11;
    int b = 10;
    int c = 9;
     smallSort ( a, b, c);
  //cout<<   smallSort ( a, b, c)<<endl;
   cout << a << ", " << b << ", " << c << endl;
   return 0;
}
*/
