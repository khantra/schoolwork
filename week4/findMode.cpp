/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/1/2017
** Description:a function named findMode that takes as parameters an array of 
int and the size of the array, and returns a vector containing the mode(s).
*********************************************************************/

#include <iostream>
#include <vector>
#include <typeinfo>       // operator typeid
using namespace std;

void sortArr(int arr[], int size)
{
int tmp;
	for(int i = 0; i < size; i++){
		for(int j = 0;j < size - 1; j++){
			if(arr[j] > arr[j+1]){
				//we need to swap
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}     
}
vector<int> findMode (int arr[],int size){
int currentNumber=0, count=0,maxFrequency=0, maxNum=0,maxPosition=0;
//identical in position to arr[], holds frequency of arr values 
vector<int>resultVector;
int frequency[size];
sortArr(arr, size);
for (int i=0; i<=size-1;i++){
    //0,1,2,3,4
    currentNumber=arr[i];
    count=0;
  // cout<<"currentNumber"<<currentNumber<<endl;
    for(int x=i+1;x<=size-1 ;x++){
    //1,2,3,4
        if(arr[i]==arr[x]){
            count++;
        }
    }
    
 // cout<<"count:"<<count<<endl;
  frequency[i]=count;
  bool numberExist=false;
    for(int j=0; j<resultVector.size();j++){
      if(arr[j]==arr[i])
        numberExist=true;
  }
  //if current max Frequency less than count than swap max values
  if(maxFrequency<count && numberExist == false){
      maxFrequency=count;
      maxNum=currentNumber;
      maxPosition=i;
      //cout<<"maxNum:"<<maxNum<<" maxFrequency:"<<maxFrequency+1<<"maxPosition:  "<<maxPosition<<" Frequency Size:" <<sizeof(frequency)/sizeof(int) <<"  resultVector Size: "<<resultVector.size()<<endl;
      resultVector.push_back(arr[maxPosition]); 
  }
  else if(count==1 && numberExist == false && maxNum !=arr[i]){
            resultVector.push_back(arr[i]);
  }

}
/*
 cout<<"maxNum:"<<maxNum<<" maxFrequency:"<<maxFrequency+1<<"maxPosition:  "<<maxPosition<< "Frequency Size:" <<sizeof(frequency)/sizeof(int) <<"  resultVector Size: "<<resultVector.size()<<endl;
  for(int i=0; i<resultVector.size();i++){
      cout<<"resultVector.at("<< i<<") : "<< resultVector.at(i)<<endl;
  }
	*/
return resultVector;
}


/*
int main()
{
 //  cout << "Hello World" << endl;
   int arr[4]={5,5,5,1};
   vector<int> x=findMode (arr,4);
   cout<<"X: "<< x.size()<<endl;
   return 0;
}
*/