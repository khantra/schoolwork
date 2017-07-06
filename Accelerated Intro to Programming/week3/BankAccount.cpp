/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Defining the class 'BankAccount' and its member functions.
*********************************************************************/
#include <iostream>
#include "BankAccount.hpp"

using namespace std;

BankAccount::BankAccount(){
     customerName="";
     customerID="";
     customerBalance=0;
}

BankAccount::BankAccount(string newCustomer, string newCustomerId, double newCustomerBalance){
     customerName=newCustomer;
     customerID=newCustomerId;
     customerBalance=newCustomerBalance;
}

double BankAccount::getCustomerBalance(){
    return customerBalance;
};
string BankAccount::getCustomerName(){
    return customerName;
};
string BankAccount::getCustomerID(){
    return customerID;
};
/*********************************************************************
** Description: Find the difference between customerBalance and the 
** amount to be withdrawn whenever there's a withdrawl. Otherwise add
** deposit amount whenever there is a deposit.
*********************************************************************/  
void BankAccount::withdraw(double withdrawAmount){
    customerBalance= customerBalance-withdrawAmount;
};
void BankAccount::deposit(double depositAmount){
    customerBalance=customerBalance+depositAmount;
};
