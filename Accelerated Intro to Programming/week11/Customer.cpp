/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Definition of Customer including member functions
and constructor
*********************************************************************/
#include "Customer.hpp"
#include <iostream>
using namespace std;
   Customer::Customer(std::string n, std::string a, bool pm){
  name=n;
   accountID=a;

   premiumMember=pm;
      // cout<< "Constructor: " <<n<<" "<<a <<" "<<endl;

   }
    std::string Customer::getAccountID(){ 
        return accountID;
    }
    std::string Customer::getName(){ 
        return name;
    }    
    std::vector<std::string> Customer::getCart(){ return cart;}
    void Customer::addProductToCart(std::string id){  cart.push_back(id);}
    void Customer::emptyCart(){  cart.clear();}    
    bool Customer::isPremiumMember(){
        return premiumMember;
    }