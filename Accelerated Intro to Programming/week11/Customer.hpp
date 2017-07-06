/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Declaration of Customer including member functions
and constructor
*********************************************************************/
#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

#include <vector>
#include "Product.hpp"

class Customer
{
private:
   std::vector<std::string> cart;
   std::string name;
   std::string accountID;
   bool premiumMember;
public:
   Customer(std::string n, std::string a, bool pm);
   std::string getAccountID();
   std::string getName();   
   std::vector<std::string> getCart();
   void addProductToCart(std::string);
   bool isPremiumMember();
   void emptyCart();
};

#endif
