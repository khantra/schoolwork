/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 1/18/2017
** Description:A program that asks the user for the name of a file 
and then tries to open it. If it cannot then the user recieves an
error message. 
*********************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	string fileName;
	int numbers=0,sum=0;
/*********************************************************************
** Description:
**Prompt User for the file name and then add the extension "text"
*********************************************************************/	
	cout << "Enter the fileName: " << endl;
    cin >> fileName;
	ifstream fileInput;
	ofstream fileOutput;
	//fileName=fileName+".text";
	fileInput.open(fileName);

	if (fileInput.is_open()){
		while(fileInput>>numbers){
			sum+=numbers;
		}		
	}
	else{
		cout<< "could not access file"<<endl;
	}
	fileInput.close();
/*********************************************************************
**Description:Open and write to Sum.text if file can be opened otherwise throw
error.
*********************************************************************/		
	fileOutput.open("sum.text");
	
	if (fileOutput.is_open()){
		fileOutput << sum;
	}
	else{
		cout<< "could not access file"<<endl;
	}

	return 0;
	
	
}