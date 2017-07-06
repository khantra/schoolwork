/* CS261- Assignment 1 - Q.5*/
/* Name: Khandakar Shadid
* Date: 04/16/2017
* Solution description: 
1. In the main function, declare an integer, x. Print the address of x (using the address of operator).
Pass x as an argument to a function void fooA(int* iptr).
2.In fooA(int * iptr), print the value of the integer pointed to by iptr, the address pointed to by iptr, and
the address of iptr itself.
3. In the main function, following the call to fooA(...), print the value of x.
*/
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
	//printf("fooA Print the value pointed to by iptr \n");
	printf("%d\n", *iptr);
     /*Print the address pointed to by iptr*/
	//printf("fooA Print the address pointed to by iptr \n");
	/*%p = pointer*/
	printf("%p\n", iptr);
     /*Print the address of iptr itself*/
//	printf("fooA Print the address of iptr itself \n");
	printf("%p\n", &iptr);

}

int main(){
    
    /*declare an integer x*/
//	printf("declare an integer x \n");

	int x=4;
    /*print the address of x*/
	//printf("print the address of x \n");

	printf("%p\n", &x);

    /*Call fooA() with the address of x*/
	fooA(&x); //&since it's expecting a pointer
    /*print the value of x*/
	//printf("print the value of x \n");

	printf("%d \n",x);

    return 0;
}
