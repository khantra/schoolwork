/*********************************************************************
** Author: Khandakar Shadid
** Date: 1/12/2017
** Description:A program that outputs the favorite animal that the user
has inputed.
*********************************************************************/

#include <iostream>
#include <string>

int main()
{
	std::string faveAnimal;
	std::cout<< "Please enter your favorite animal."<<std::endl;
	std::cin>>faveAnimal;
	std::cout<<"Your favorite animal is the "<< faveAnimal;
	std::cout<< "."<<std::endl;
	
	return 0;
}
