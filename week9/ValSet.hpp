#include <iostream>
#include <cstdlib> 
#include <cstring>
using namespace std;

template <class T>
class ValSet
{
private:
T *aptr;
int arraySize;
//invariant
int numberOfValues;

void subError() const; // Handles subscripts out of range

public:

/*
a default constructor that initializes the pointer data member to point to an array of size 10,
 initializes the variable that stores the size of the array to 10
  initializes the variable that stores the number of values in the set to zero
*/

ValSet();

/*
a copy constructor that initializes the pointer data member to point to an array of the same
size as the one being copied copies over the array values, and also copies the values for 
the size of the array and the number of values in the set
*/

// Copy constructor
ValSet(const ValSet &); 

// Destructor
~ValSet(); 

int size() const{ return arraySize; }
bool contains(T value);
bool isEmpty();
void add(T value);
void remove(T value);

// Overloaded [] operator
const ValSet& operator = (const ValSet<T> & co);//Assignment Operator

// Output array
void print() const; 

};
