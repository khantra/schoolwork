
#include <iostream>
using namespace std;
#include "PreferredProject.hpp"


	PreferredProject::PreferredProject(double newHours,double newMaterials,double newTransportation):
	CustomerProject( newHours, newMaterials, newTransportation){

	}
	  double PreferredProject::billAmount(){
/*sum of 85% of the materials costs, 90% of the transportation costs, 
and $80 times the number of hours up to a maximum of 100 hours (any hours beyond 100 are free)	    
*/
	      double x;
	      if(getHours()>=100){
	       
	      x=(getMaterials()*.85)+(getTransportation()*.9);
	      }
	      else{
	      x=(getHours()*80)+(getMaterials()*.85)+(getTransportation()*.9);
	      }
	   
	   return x;
	  }

	