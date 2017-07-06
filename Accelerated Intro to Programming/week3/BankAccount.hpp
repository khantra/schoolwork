/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/25/2017
** Description: Declaring the class 'BankAccount' and its member functions.
*********************************************************************/

#ifndef BankAccount_HPP
#define BankAccount_HPP
using namespace std;
#include <string>

// Defines the interface of the Movie class
class BankAccount 
{
private:
    string customerName;
    string customerID;
    double customerBalance;

public:
    BankAccount ();
    BankAccount (string, string, double);
    
    double getCustomerBalance();
    string getCustomerName();
    string getCustomerID();
    
    void withdraw(double);
    void deposit(double);
};
#endif