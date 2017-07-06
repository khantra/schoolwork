/* CS261- Assignment 1 - Q.5*/
/* Name: Khandakar Shadid
* Date: 04/16/2017
* Solution description: Consider the structure student in Q1.c. Modify the above sort(...) function from Q.3 to sort an array of n
students based on their scores in ascending order. The function prototype is void sort(struct student*
students, int n). The IDs and scores of the students are to be generated randomly (see use of rand()). Also
you must make sure that IDs are unique.
*/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
	 /*Sort the given array number , of length n*/
	int isSorted = 0; //bool
	while (isSorted !=1) {
		isSorted = 1;
	//	printf("Made It Here. \n");
		int i = 0; //‘for’ loop initial declarations are only allowed in C99 mode

		for (i = 0; i < n - 1; i++) {
			if (students[i ].score > students[i + 1].score) {
			//	printf("Made It Here. %d %d \n", students[i].score, students[i + 1].score);

				struct student tmp;
				tmp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = tmp;
				//printf("After Swap: %d %d \n", students[i].score, students[i + 1].score);

				isSorted = 0;
			}
		}
		

	}

}
void generate(struct student* students, int n) {
	/*Generate random and unique ID and scores for n students, ID being between 1 and 10, scores between 0 and 100*/
	int count = 0;
	for (count = 0; count < n; count++) {
		//srand(time(NULL));
		/*
		make id unique -- Forgot and couldn't finish in the end.
		int x = rand() % 10 + 1;
		if()
		while (count == n-1 && students[count - 1].id == x)
			x = rand() % 10 + 1;
		*/
		students[count].id = rand() % 10 + 1;
		students[count].score = (rand() % 100);
		//printf("%d, %d\n", students[count].id, students[count].score);
	}
}
int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
	int n = 28;
    /*Allocate memory for n students using malloc.*/
	struct student* newStudent = malloc(n * sizeof(struct student));
    /*Generate random and unique IDs and random scores for the n students, using rand().*/
	generate(newStudent, n);
    /*Print the contents of the array of n students.*/
//	printf("---------- Unsorted Array ----------\n");
	int i = 0;
	for (i = 0; i < n; i++)
		printf("ID%3d Score%4d\n", newStudent[i].id, newStudent[i].score);
	/*Pass this array along with n to the sort() function*/
	sort(newStudent, n);

	/*Print the contents of the array of n students.*/
	//printf("---------- Sorted list ---------- \n");
	int x = 0;
	for (x = 0; x < n; x++) {
		printf("ID%3d Score%4d\n", newStudent[x].id, newStudent[x].score);
	}    
	
	return 0;
}
