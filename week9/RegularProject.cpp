
#include <iostream>
using namespace std;
#include "RegularProject.hpp"


	RegularProject::RegularProject(double newHours,double newMaterials,double newTransportation):
	CustomerProject( newHours, newMaterials, newTransportation){

	}
	  double RegularProject::billAmount(){
	      double x=(getHours()*80)+getMaterials()+getTransportation();
	   return x;
	  }

	
