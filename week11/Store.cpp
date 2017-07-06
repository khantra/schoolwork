/*********************************************************************
** Author: Khandkar shadid
** Date:3/16/2017
** Description: Class Definition of Product including member functions
and constructor
*********************************************************************/
#include <iostream>
#include "Store.hpp"
#include <algorithm>    // std::transform
#include <iostream>
#include <vector>
using namespace std;

void Store::addProduct(Product* p)
{  // cout<<"Store::addProduct "<<p-> getTitle()<<endl;
    inventory.push_back(p);
}
void Store::addMember(Customer* c)
{
    members.push_back(c);
    
}


Product*  Store::getProductFromID(std::string id)
{
    for(int i = 0; i < inventory.size(); i++)
    {
        Product* p=inventory.at(i);

        if(p->getIdCode()== id)
        {                
          //  cout<<"getProductFromID:: Product Exist and Its ID Is: "<<(*inventory.at(i)).getIdCode()<<endl;

            return p;
        }
    }
    return NULL;
}

Customer*  Store::getMemberFromID(std::string id)
{
    for(int i = 0; i < members.size(); i++)
    {        
       Customer* p=members.at(i);
       // cout<<"getMemberFromID:: Searched ID: "<<id<<" Customer: "<<(*members.at(i)).getAccountID()<<" "<<(*members.at(i)).getName()<<endl;
        if(p->getAccountID()==id){
      // cout<<"getMemberFromID:: member Exist and Their ID Is: "<<(*members.at(i)).getAccountID()<<endl;

            return p;            
        }

    }
    return NULL;
}


void Store::productSearch(std::string str){
    int count=0;
    for(int i = 0; i < inventory.size(); i++)
    {
        Product* p=inventory.at(i);
        //cout<<"productSearch:: str:  "<<str<<" Product ID: "<<p->getIdCode()<<" Product Title: "<<p->getTitle()<<" Product Description: "<<p->getDescription()<<endl;
       // cout<<" (p->getTitle()).find(str)): "<<(p->getTitle()).find(str)<<endl;
	   
	   string temp= p->getTitle();
	std::transform(temp.begin(), temp.end(),temp.begin(), ::toupper);
	   string temp2= p->getDescription();
	std::transform(temp2.begin(), temp2.end(),temp2.begin(), ::toupper);


	   string temp3=str;
	 
	std::transform(temp3.begin(), temp3.end(),temp3.begin(), ::toupper);

		
	   /*
	   cout<<"productSearch::getTitle:: " <<temp<<endl;
	   cout<<"productSearch::getDescription:: " <<temp2<<endl;
	   cout<<"productSearch::getDescription:: " <<temp3<<endl;
	   */
	   if(temp.find(temp3) !=string::npos ||  temp2.find(temp3) !=string::npos)
      //  if((p->getTitle()).find(str) !=string::npos || (p->getDescription()).find(str) !=string::npos)
		{
            count++;
        cout<<p->getTitle()<<endl<<"ID code: "<<p->getIdCode()<<endl<<"Price: $"<<p->getPrice()<<endl<<p->getDescription()<<endl<<endl;
        }

    }


}

void Store::addProductToMemberCart(std::string productID, std::string memberID){

     if(getProductFromID(productID)==NULL){
        cout << "Product #"<<productID<<" not found."<<endl;
     }
    else if(getMemberFromID(memberID)==NULL){
        cout << "Member #"<<memberID<<" not found."<<endl;
    }
	else if(getProductFromID(productID)->getQuantityAvailable()<1){
        cout << "Product #"<<productID<<" is currently out of stock."<<endl;
	}
    else{
    //cout << "addProductToMemberCart:: adding to "<<getMemberFromID(memberID)->getName() << " 's cart " <<endl<<"Product ID: "<<productID <<" memberID ID: "<<memberID<<endl;
    getMemberFromID(memberID)->addProductToCart(productID);
    }
}


void Store::checkOutMember(std::string memberID){
 
float subTotal=0, shippingCost=0,
 standardShippingRate=.07,total=0;

    if(getMemberFromID(memberID)==NULL){
        cout << "Member #"<<memberID<<" not found."<<endl;
    }
    else{
        /*Otherwise prints out the title and price for each product in the cart and decreases 
        the available quantity of that product by 1.
        */
       // cout << "checkOutMember:: Member Exists "<<memberID<<endl;
        Customer* p=getMemberFromID(memberID);
        vector<std::string> newCart;
        newCart=p->getCart();
       // cout<<"newCart.size():"<<newCart.size()<<endl;
        if(newCart.size()!=0){
        for(int i=0;i<newCart.size();i++){
       //     cout<<"checkOutMember "<< p->getName()<< ":: Prdouct In Cart Name "<<newCart.at(i)<<endl;
            Product* newProduct;            
            if((newProduct=getProductFromID(newCart.at(i))) != NULL){
                /*-If any product has already sold out, then on that line it should print 
                'Sorry, product #[idCode goes here], "[product name goes here]", is no longer available.' 
                */
                if(newProduct->getQuantityAvailable() < 1){
                    cout<<"Sorry, product #"<<newProduct->getIdCode() <<",\""<<newProduct->getTitle()<<"\", is no longer available."  <<endl;
                }
                else {
                    cout<<newProduct->getTitle()<<" - $"<<newProduct->getPrice()<<endl;
                    newProduct->decreaseQuantity();
                    //cout<<" Quantity Available: "<< newProduct->getQuantityAvailable()<<endl;
                   // cout<<subTotal<<endl;

                    subTotal=subTotal+newProduct->getPrice();
                  //  cout<<subTotal<<endl;
                    if(p->isPremiumMember()){
						shippingCost=0;
                    //cout<<" shipping Cost: "<< shippingCost<<endl;
						
					}
					else{
						shippingCost=standardShippingRate*subTotal;
						//cout<<" shipping Cost: "<< shippingCost<<endl;						
					}
					total=shippingCost+subTotal;
                }
                

            }
  
            
        }
	        cout << "shippingCost: $"<<shippingCost<<endl<< "subTotal: $"<<subTotal<<endl<<"total: $"<< total<<endl;
			
			p->emptyCart();
		}
		else{
		    cout<<"There are no items in the cart."<<endl; 
		}
    }


}
