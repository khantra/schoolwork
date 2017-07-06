/*********************************************************************
** Author:/ Khandakar Shadid
** Date: / 2/8/2017
** Description:/ A case-insensitive selection sort that takes an
array of strings, and the size of the array. 
*********************************************************************/

#include <iostream>
#include <string>
 using namespace std;


bool strCMP(string currentStr, string minStr ){
string oneUpper, twoUpper;
currentStr[0]=toupper(currentStr[0]);
minStr[0]=toupper(minStr[0]);

oneUpper=currentStr;
twoUpper=minStr;
//cout <<"One  |  "<< oneUpper<<"  |  "<< int(oneUpper)<<"  |"<< "  Two  |  "<<twoUpper<<"  |  "<<int(twoUpper)<<endl;

return oneUpper < twoUpper;
}


void stringSort(string array[], int size)
{
int startScan, minIndex;
string minValue;

for (startScan = 0; startScan < (size - 1); startScan++){
    minIndex = startScan;
    minValue = array[startScan];
    // cout<<"minIndex = startScan=  " <<startScan<<"  minIndex = startScan=  " <<startScan<< "minValue = array[startScan]=  " <<array[startScan]<< endl;
for(int index = startScan + 1; index < size; index++){
    string word = array[index];
/*********************************************************************
** Description:
p= x= word[0] (is upper) 
Q= y= minValue (is upper)
R= both should be made case insensitve
because ascii captial letters are numbered later than regular letters)
(!p v !Q)--> R
(R)->strCMP
strCMP=function(x,y){ return toUpper(x) < toupper(y) }
*********************************************************************/

    if (strCMP(word, minValue) == true){
        minValue = array[index];
        minIndex = index;
 }
}   
    array[minIndex] = array[startScan];
    array[startScan] = minValue;
 }
}

/*
  void showStrArray(const string sarray[], int size){
     for (int count = 0; count < size; count++)
     cout << sarray[count] << " ";
 cout << endl;
 }
  
int main(){
 const int SIZE = 18;
 // Array of unsorted values
   string dayName[SIZE] = {"t", "M","man","manner", "T", "d","D","a","Z","Sunday", "Monday", "Tuesday", "Wedensday", "Thursday", "Friday", "Saturday","alligator","Zebra"};
 // Display the values 
 cout << "The unsorted values are\n";
  showStrArray(dayName, SIZE);

stringSort(dayName,SIZE);
 // Display the values again
 cout << endl<<"The sorted values are\n";
 showStrArray(dayName, SIZE);
 return 0;
}
*/
