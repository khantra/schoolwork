/*********************************************************************
** Author: Khandakar Shadid	
** Date:3/8/17
** Description: A function that processes postfix expressios
*********************************************************************/


#include<iostream>
#include<stack>
#include<string>
#include <cstring>
using namespace std;

double operate(char operation, double num1, double num2)
{
	if(operation == '+'){ 
	    return num1 +num2;
	    
	}
	else if(operation == '-'){ 
	    return num1 - num2;
	    
	}
	else if(operation == '*'){ 
	    return num1 * num2;
	    
	}
	else if(operation == '/'){ 
	    return num1 / num2;
	    
	}

	return 0; 
}
double postfixEval (char functionString[])
{
stack<double> tempStack;

	for(int x = 0;x< strlen(functionString);x++) {

	if(isdigit(functionString[x])){
	    // stops at first number ie 3 of 300 or 1 of 10
        //300 has 3 digits 10 has two
        //[0]3 [1]3*10 [2]3*10*10         
        //[0] 0*10 +3  [1] (0*10 +3)*10 [2] (0*10 +3) *10^2
        
		//cout<<functionString.length() <<" digit: " <<functionString[x]<<endl;
		
		double operand = 0; 

			while(x<strlen(functionString) && isdigit(functionString[x])) {
				/*
				cout<<"operand= "<<operand <<endl;
				cout<<"operand: "<<operand<<" *10= "<<operand*10  <<endl;
				cout<<"functionString[x] - '0'= "<<functionString[x] - '0'  <<endl;
				cout<<operand*10<< " + "<< functionString[x] - '0'<<"= "<< operand*10 + (functionString[x] - '0')<<endl;
				*/
				operand = (operand*10) + (functionString[x] - '0'); 
				x++;
			}
    //cout<<functionString[x-1]<<" "<<functionString[x]<<endl;
			    x--;

			tempStack.push(operand);
		}
		
		else if(functionString[x]=='+' || functionString[x]=='-' || functionString[x]=='*' || functionString[x]=='/') {
			double num2 = tempStack.top(); 
			tempStack.pop();
			double num1 = tempStack.top(); 
			tempStack.pop();

			double value = operate(functionString[x], num1, num2);
			tempStack.push(value);
		}
		 
	}
	return tempStack.top();
}
/*
int main()
{
   cout << "Testing" << endl; 
   char name1[40]="8 2 /";
   char name2[40]="25 12 7 - 2 * /";
   char name3[40]="3 4 5 * 6 / +";
   char name4[40]="300 23 + 43 21 - * 84 7 + /";
   cout<< postfixEval(name1)<<endl;
      cout<< postfixEval(name2)<<endl;
  cout<< postfixEval(name3)<<endl;
      cout<< postfixEval(name4)<<endl;
   return 0;
}
*/
