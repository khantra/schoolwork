#include <iostream>
#include <vector>
#include "Store.hpp"
using namespace std;

int main () { 
            cout << "   -------------------STARTING PROGRAM-----------------     "<<endl;

    //Product::Product(std::string id, std::string t, std::string d, double p, int qa)
    Product testOne("123","red blender", "sturdy blender perfect for making smoothies and sauces",350.0,5),* testTwo,testThree("003","Blue blender", "COmes in Red",5.5,2),
    testFour("345","hot air balloon", "fly into the sky in your own balloon - comes in Red, blue or chartreuse",700.0,5);
    //Customer(std::string n, std::string a, bool pm);
    Customer testCustomer("Jonah", "10", false), * testCustomerTwo=new Customer("Norah", "0", false),
    * testCustomerThree=new Customer("Arthur", "1", true);
    vector<std::string> newCart;
    newCart= testCustomer.getCart();

     
    testOne.decreaseQuantity();
    
    
    testThree.decreaseQuantity();
    Store x;   



   x.addProduct(&testOne);

   Product * testFive=&testFour;
      x.addProduct(testFive);

   //Product*  Store::getProductFromID(std::string id)
  testTwo=x.getProductFromID(testOne.getIdCode());


    x.addMember(testCustomerTwo);
        x.addMember(&testCustomer);
    //testCustomerTwo=x.getMemberFromID("1");
		    cout<<"Call fucntion to see if returns pointers"<<endl;
    cout<<x.getMemberFromID("0")<<endl;
     cout<<"x.getMemberFromID(1)"<<x.getMemberFromID("10")<<endl;
	     cout<<"Testing Store productSearch"<<endl<<endl;
    x.productSearch("Red");
    cout<<"Testing addProductToMemberCart."<<endl;
    //    void addProductToMemberCart(std::string productID, std::string memberID);
    x.addProductToMemberCart(testOne.getIdCode(),testCustomerTwo->getAccountID() );
	    x.addProductToMemberCart(testOne.getIdCode(),testCustomerTwo->getAccountID() );

    x.addProductToMemberCart(testFour.getIdCode(),testCustomerTwo->getAccountID() );
       x.addProductToMemberCart(testFour.getIdCode(),"0" );

      x.addProductToMemberCart(testOne.getIdCode(),"122" );
        x.addProductToMemberCart("Zanzibar","0" );
            testOne.decreaseQuantity();
    testOne.decreaseQuantity();
	    testOne.decreaseQuantity();


        x.checkOutMember("0");
//        x.checkOutMember("10");
      //  cout<<"testCustomerTwo ID: " <<testCustomerTwo->getAccountID()<<endl;
    //cout<<"testCustomerTwo isPremiumMember:  " <<testCustomerTwo->isPremiumMember()<<endl;
    return 0;
}
