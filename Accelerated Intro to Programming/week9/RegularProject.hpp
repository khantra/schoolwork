#include <iostream>
using namespace std;
#include "CustomerProject.hpp"


class RegularProject: virtual public CustomerProject{
	private:
	double hours;
    double materials;
    double transportation ;
	
	public:
	RegularProject(double newHours,double newMaterials,double newTransportation);
	double billAmount();

};

