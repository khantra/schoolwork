/* CS261- Assignment 1 - Q.5*/
/* Name: Khandakar Shadid
* Date: 04/16/2017
* Solution description: 
1.a function int foo(int* a, int *b, int c) which should perform the following computations
1. Set the value of a to twice its original value.
2. Set the value of b to half of its original value.
3. Assign a + b to c.
4. Return the value of c

2.In the main function, declare three integers x,y, and z, and assign them values 5, 6, and 7
respectively. Print the values of x,y, and z. Call foo(...) appropriately passing x,y, and z as
arguments and print the returned value. After the function call, print out the values of x,y, and z
again. Answer the following question in a comment at the bottom of the file: Is the return value
different than the value of z? Why?
*/
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
	*a = (*a) * 2;
    /*Set b to half its original value*/
	*b = *b/2;
    /*Assign a+b to c*/
	c = *a + *b;
    /*Return c*/
	return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
	int x=5, y = 6, z = 7, tmp;
    /*Print the values of x, y and z*/
	printf("X = %d \n y = %d \n z = %d \n", x,y,z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
	tmp = foo(&x, &y, z);
    /*Print the value returned by foo*/
	printf("The result of foo() is: %d\n", tmp);

    /*Print the values of x, y and z again*/
	printf("X = %d \n y = %d \n z = %d \n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/
	/*
	Yes, because it wasn't passed by reference unlike x and y.
	*/
    return 0;
}
    
    
