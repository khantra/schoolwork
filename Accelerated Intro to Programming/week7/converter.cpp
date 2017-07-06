
/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/15/2017
** Description:/  Write two recursive functions - one should take as 
a parameter a C++ string of '1's and '0's that are the binary representation 
of a positive integer, and return the equivalent int value; the other should
 take as a parameter a positive int value, and return a C++ string of '1's and
 '0's that are the binary representation of that number (no leading zeros). 
*********************************************************************/
#include <iostream>
#include <string>
#include <math.h>       /* pow */
using namespace std;
string reverseString(string str){
    int size = str.length();
	string temp = "";
    // Swap character starting from two
    // corners
    for (int i = size - 1; i >= 0; --i)
       temp += str[i];
	str=temp;
  /*  for (int i=0; i<n; i++)
       cout<<str[i]<<", "; 
    cout<<endl; */
    return str;
}


int binToDecConverter( string arr, int counter)
{
    if ( counter == 0 ){  // if 0 then we have reached the end (or in this case the start of the array)
    return 0 ; 
    }
  else
    {   int total=binToDecConverter( arr, counter - 1 ) ;
        int multiplier=pow(2,counter-1);
       
        int tmp=arr[counter-1]- '0';
        total=total+(tmp *multiplier);
    /*    cout<<"counter"<<" | "<< counter-1 << " | pow(2,"<<counter-1<<") | "<<multiplier<<
        "| arr[counter-1]- 0"<<" | "<< tmp <<" | Total"<<" | "<< total <<endl; */ 
         return total  ;
      


    }
}


int binToDec(string arr){
    arr=reverseString(arr);
return binToDecConverter(arr, arr.length());
}


///////////////////////////////////////////////////////////////////////
string &  decToBinConverter(string & arr,int counter, int number){
    int remainder;
	int tmpCounter=0;
    if (number == 0 ){
      // cout<<"A) ["<<counter<<"] "<<arr[counter]<<endl;
         arr[counter]= '0';

        return arr;
        
    }
	else{
    remainder = number % 2;
     // cout<<"B) ["<<counter<<"]"<<arr[counter]<<" | "<<number<<" | "<<remainder<<endl;
    decToBinConverter(arr,counter-1,number / 2);
   
   if(remainder==0 &&counter !=0){
    arr[counter]= '0';
	}
	
   if(remainder==1){
    arr[counter]= '1';
   }
   
   //cout<<"c) ["<<counter<<"] "<<arr[counter]<<" | "<<endl;
   /*
   if(counter==arr.size()-1){

			for (int i=0; i<arr.size()-1; i++)
				cout<<" - "<<arr[i]<< " | "<<endl;
		
   }
   */
return arr;
	}

}

string decToBin(int number){

string tmp("00000000");

tmp=decToBinConverter(tmp,tmp.length()-1, number);



int firsOne=tmp.find("1");
/*
			for (int i=0; i<tmp.length()-1; i++)
				cout<<" - "<<tmp[i]<< " | "<<endl;
*/			
if(firsOne>0){

//cout<<tmp.at(tmp.length()-1)<<" | "<<firsOne<<" | "<<tmp.length()-1<<endl;
return tmp.substr(firsOne,tmp.length()-1);
}	
else if(firsOne<0){
/*********************************************************************
** Description: I Wasn't sure if when the number is 0 if we should 
return '0' or '00000000'
**uncomment [  return tmp="0"; ] and comment out [ return tmp; ] 
if zero should be returned as a single "0"

*********************************************************************/	
	
	//uncomment this if zero should be returned as a single "0"
	return tmp="0";	
	
	//return tmp;
}	
else{
	return tmp;
}	


}

int main()
{
    string binNumber("10011011"); //22
    string binNumberTwo("100001"); //33
    string binNumberThree("11111111"); //255
	string binNumberFour("00000000"); //0
	string binNumberFive("00010000");//16
    int decNumber=255;
    int decNumberTwo=177;
    int decNumberThree=130;	
    int decNumberFour=119;
    int decNumberFive=0;
	int decNumberSix=16;			
    string tmp= decToBin(decNumber);
	string tmpTwo=decToBin(decNumberTwo);
	string tmpThree=decToBin(decNumberThree);
	string tmpFour=decToBin(decNumberFour);
	string tmpFive=decToBin(decNumberFive);
	string tmpSix=decToBin(decNumberSix);

    for (int i=0; i<tmp.length(); i++)
       cout<<tmp[i]<<" | "; 
   
	cout<<"(255)"<<endl;

    for (int i=0; i<tmpTwo.length(); i++)
       cout<<tmpTwo[i]<<" | "; 
   
	cout<<"(177)"<<endl;
	

    for (int i=0; i<tmpThree.length(); i++)
       cout<<tmpThree[i]<<" | "; 
   
	cout<<"(130)"<<endl;


    for (int i=0; i<tmpFour.length(); i++)
       cout<<tmpFour[i]<<" | "; 
   
	cout<<"(119)"<<endl;
	
	    for (int i=0; i<tmpFive.length(); i++)
       cout<<tmpFive[i]<<" | "; 
   
	cout<<"(0)"<<endl;
	
	    for (int i=0; i<tmpSix.length(); i++)
       cout<<tmpSix[i]<<" | "; 
   
	cout<<"(16)"<<endl;
	
   cout << " | 10011011| " << binToDec(binNumber)<< " | 100001 | " << binToDec(binNumberTwo)<<" | 11111111 | " 
   << binToDec(binNumberThree)<<" | 00000000 | " << binToDec(binNumberFour)<<" | 00010000 | " << binToDec(binNumberFive)<<endl; 

   return 0;
}

