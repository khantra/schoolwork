/*
Write a class called CustomerProject. 
It should have three double fields called hours (the number of hours the project took),
materials (the cost of materials) and transportation (transportation costs), in that order.
It should have get and set methods for each field.  
It should have a constructor that takes as parameters the values for each field and calls 
the set methods to initialize them. 
It should have a pure virtual function called billAmount that takes no parameters and returns a double.
*/

#include <iostream>
using namespace std;
class CustomerProject{
	private:
	double hours;
    double materials;
    double transportation ;
    
	public:
	CustomerProject(double newHours,double newMaterials,double newTransportation);

	
	void setHours(double newHours);
	void setMaterials(double newMaterials);
    void setTransportation(double newTransportation);
    
    virtual double billAmount()=0;

    double getHours();
    double getMaterials();
    double getTransportation();
};