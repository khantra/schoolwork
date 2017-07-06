
#include <iostream>
using namespace std;
#include "CustomerProject.hpp"


	CustomerProject::CustomerProject(double newHours,double newMaterials,double newTransportation){
        hours=newHours;
        materials=newMaterials;
        transportation=newTransportation;
	}
	
	void CustomerProject::setHours(double newHours)
	{
        hours=newHours;
	}

	void CustomerProject::setMaterials(double newMaterials)
	{
        materials=newMaterials;

	}
	
	void CustomerProject::setTransportation(double newTransportation)
	{
        transportation=newTransportation;

	}

    double CustomerProject::getHours(){return hours;};
    double CustomerProject::getMaterials(){return materials;};
    double CustomerProject::getTransportation(){return transportation;};
   