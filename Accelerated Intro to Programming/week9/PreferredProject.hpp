#include <iostream>
using namespace std;
#include "CustomerProject.hpp"


class PreferredProject: virtual public CustomerProject{

	public:
	PreferredProject(double newHours,double newMaterials,double newTransportation);
	double billAmount();

};

