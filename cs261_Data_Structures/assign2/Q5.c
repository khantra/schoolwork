/* CS261- Assignment 1 - Q.5*/
/* Name: Khandakar Shadid
 * Date: 04/16/2017
 * Solution description: 
 Write a function void sticky(char* word) where word is a single word such as “sticky” or “RANDOM”.
 sticky() should modify the word to appear with “sticky caps” (http://en.wikipedia.org/wiki/StudlyCaps) , that
 is, the letters must be in alternating cases(upper and lower), starting with upper case for the first letter. For
 example, “sticky” becomes “StIcKy” and “RANDOM” becomes “RaNdOm”. Watch out for the end of the
 string, which is denoted by ‘\0’. You can assume that legal strings are given to the sticky() function.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch) {
	return ch - 'a' + 'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch) {
	return ch - 'A' + 'a';
}

void sticky(char* word) {
	/*Convert to sticky caps*/
	printf("Sticky %d \n", strlen(word));
	int length = strlen(word);
	int i = 0;//‘for’ loop initial declarations are only allowed in C99 mode
	for (i = 0; i < length-1; i++)
	{
		if (word[i] == '\0') { //base case for exit= null character 
			return;
		}
		if (i % 2!=0) { //if even=lowercase
			printf("Sticky Even %d %c \n", i,word[i]);
			if (word[i] >= 'A' && word[i] <= 'Z')
			word[i] = toLowerCase(word[i]);
		}

		else { //if odd =lowercase
			printf("Sticky Odd %d %c \n",i, word[i]);
			if (word[i] >= 'a' && word[i] <= 'z')
			word[i] = toUpperCase(word[i]);
		}
	
	}

}

int main() {
	
	char str1[200];
	//printf("%d \n", sizeof(str1)/sizeof(char));
	printf("Enter a String:");
	scanf("%s", &str1, sizeof(str1) / sizeof(char));
	sticky(str1);
	printf("%s \n", str1);
	return(0);
}