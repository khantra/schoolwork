/* CS261- Assignment 1 - Q.5*/
/* Name: Khandakar Shadid
* Date: 04/16/2017
* Solution description: 
1.Write a function struct student* allocate() that allocates memory for ten students and returns the
pointer.
2.Write a function void generate(struct student* students) that generates random IDs and scores for
each of the ten students and stores them in the array of students. You can make use of the rand()
function to generate random numbers. Ensure that IDs are unique and between 1 and 10 (both
inclusive) and score is between 0 and 100 (both inclusive).
3. Write a function void output(struct student* students) that prints the ids and scores of all the
students. the output of the function need not to be sorted.
Write a function void summary(struct student* students) that prints the minimum score, maximum
score and average score of the ten students.
4.Check that students is not NULL (NULL == 0) before you attempt to free it.
5. Write a function void deallocate(struct student* stud) that frees the memory allocated to students.
*/
 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#define ALLOCSIZE 10 /* size of available space */
struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
	//struct student* newStudent = malloc(ALLOCSIZE * sizeof(struct student));

     /*return the pointer*/
	//return newStudent;
	return (struct student *) malloc(ALLOCSIZE * sizeof(struct student));
}

void generate(struct student* students){
	/*Generate random and unique ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
	int count= 0; //‘for’ loop initial declarations are only allowed in C99 mode
	for (count = 0; count < 10; count++) {
		//generate random numbers between 1-10
		students[count].id = rand() % 10 + 1;
		//generate random numbers between 0-100
		students[count].score = (rand() % 100);
		//printf("%d, %d\n", students[count].id, students[count].score);
	}
}

void output(struct student* students){
     //Output information about the ten students in the format:
	//ID1 Score1

	int i;
	for (i = 0; i < ALLOCSIZE; i++) {
		printf("ID %d Score %d\n", students[i].id, students[i].score);
	}

}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/


	int minNumber = -1,maxNumber = -1,sum = 0, average;
	int i = 0;
	for ( i = 0; i < ALLOCSIZE; i++)
	{
		if (minNumber > students[i].score || minNumber == -1)
			minNumber = students[i].score;

		if (maxNumber < students[i].score)
			maxNumber = students[i].score;

		sum += students[i].score;
	}

	average = sum / ALLOCSIZE;
	printf("minimum: %d\n", minNumber);
	printf("maximum: %d\n", maxNumber);
	printf("average: %d\n", average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if (stud != 0)
		free(stud);
	
}

int main(){
    struct student* stud = NULL;
    
	/*call allocate*/
	stud = allocate();
	/*call generate*/
	generate(stud);
	/*call output*/
	output(stud);
	/*call summary*/
	summary(stud);
	/*call deallocate*/
	deallocate(stud);

    return 0;
}
