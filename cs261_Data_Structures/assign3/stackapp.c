/* CS261- Assignment2*/
/* Name: Khandakar Shadid
* Date: 04/23/2017
* Solution description:
Define isBalanced funcition which checks if a statement has unbalanced
braces.

*/


/*	stack.c: Stack application. */
#include <stdio.h>
#include <stdlib.h>
#include "dynArray.h"


/* ***************************************************************
Using stack to check for unbalanced parentheses.
***************************************************************** */

/* Returns the next character of the string, once reaches end return '0' (zero)
	param: 	s pointer to a string 	
	pre: s is not null		
*/
char nextChar(char* s)
{
	static int i = -1;	
	char c;
	++i;	
	c = *(s+i);			
	if ( c == '\0' )
		return '\0';	
	else 
		return c;
}

/* Checks whether the (), {}, and [] are balanced or not
	param: 	s pointer to a string 	
	pre: s is not null	
	post:	
*/

/*
Makes sure s pointer is not empty
Push Starting braces into stack
and then pop each time a closing brace is detceted.
if stack is empty at the end
	then the same number of pushes were made as pops and the braces are balnaced
	if the stack is not empty we reutrn false that means there is a  single brace
otherwise the braces are not balanced
since memory has been allocated for the stack it has to then be deallocated

*/
int isBalanced(char* s)
{
	if (s == NULL) {  //if s is than returns true could just as well be false..
		return 1;
	}
	char next = nextChar(s); //Next Holds the next current character starting with the first
	DynArr *temp=newDynArr(30); //Stack that keeps track of braces
	int boolBalanced; //because return is called after freee

	/* FIXME: You will write this function */
	
	while (next != '\0') {
		if (next == '{' || next == '(' || next == '[') {

			pushDynArr(temp, next);

		}
		else if (next == '}' || next == ')' || next == ']' ) {
			if (temp == NULL)
				return 0;

			popDynArr(temp);
		}

		next = nextChar(s);
	}

	boolBalanced = isEmptyDynArr(temp);

	deleteDynArr(temp);

	return boolBalanced;
}

int main(int argc, char* argv[]){
	
	char* s = argv[1];
	int res;

	printf("Assignment 2\n");

	res = isBalanced(s);

	if (res)
		printf("The string %s is balanced\n", s);
	else
		printf("The string %s is not balanced\n", s);

	return 0;
}

