/*
 * CS 261 Assignment 5
 * Name: Khandakar Shadid
 * Date: 5/28/2017
 */

#include "dynamicArray.h"
#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Loads into heap a list from a file with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listLoad(DynamicArray* heap, FILE* file)
{
    const int FORMAT_LENGTH = 256;
    char format[FORMAT_LENGTH];
    snprintf(format, FORMAT_LENGTH, "%%d, %%%d[^\n]", TASK_NAME_SIZE);
    
    Task temp;
    while (fscanf(file, format, &temp.priority, &temp.name) == 2)
    {
        dyHeapAdd(heap, taskNew(temp.priority, temp.name), taskCompare);
    }
}

/**
 * Writes to a file all tasks in heap with lines formatted like
 * "priority, name".
 * @param heap
 * @param file
 */
void listSave(DynamicArray* heap, FILE* file)
{
    for (int i = 0; i < dySize(heap); i++)
    {
        Task* task = dyGet(heap, i);
        fprintf(file, "%d, %s\n", task->priority, task->name);
    }
}

/**
 * Prints every task in heap.
 * @param heap
 */
void listPrint(DynamicArray* heap)
{
    DynamicArray* temp = dyNew(1);
    dyCopy(heap, temp);
     while (dySize(temp) > 0)
    {
        Task* task = dyHeapGetMin(temp);
        printf("\n");
        taskPrint(task);
        printf("\n");
        dyHeapRemoveMin(temp, taskCompare);
    }
    dyDelete(temp);
}

/**
 * Handles the given command.
 * @param list
 * @param command
 */
void handleCommand(DynamicArray* list, char command)
{

	char *fName = malloc(sizeof(char) * 256);
	char *fPriority = malloc(sizeof(char) * 256);
	
	
	char *desc = malloc(sizeof(char) * 256);
	int priority;

	// FIXME: Implement
	/*
	//while (fgetc(stdin) != '\n'){

	while (exitCode !=1)
	{
		if (command == 'a') {
			printf("Please enter the task description: ");
			fgets(desc, 100, stdin);

			if (desc[strlen(desc) - 1] == '\n') {
				desc[strlen(desc) - 1] = 0;
			}

			printf("Please enter the task priority (0-999): ");
			fgets(fPriority, 100, stdin);
			if (fName[strlen(fName) - 1] == '\n') {
				fName[strlen(fName) - 1] = 0;
			}
			sscanf(fPriority, "%d", &priority);

			Task *task = taskNew(priority, desc);
			dyHeapAdd(list, task, taskCompare);
			printf("The task '%s' has been added to the list.\n", desc);
			printf("\n");

		}

		else if (command == 'p') {
			if (dySize(list) == 0)
				printf("Your to-do list is empty!\n");
			else
				listPrint(list);
		}
		else if (command == 'e') {
			printf("GoodByte!\n");
			exitCode=1;
		}


	}
	*/


	switch (command) {
	//l to load the list from a file (function implemented for you).

	case 'l':
		printf("What is the Name of the file? :");
		//Reads characters from stream and stores them as a C string
		//gets uses stdin as source, but it does not include the
		//ending newline character in the resulting string and does not allow 
		//to specify a maximum size for str (which can lead to buffer overflows).
		fgets(fName, 100, stdin);

		if (fName[strlen(fName) - 1] == '\n')
			fName[strlen(fName) - 1] = 0;

		//FILE *fopen(const char *filename, const char *mode);
		FILE *fileReader = fopen(fName, "r");

		listLoad(list, fileReader);

		printf("The list has been loaded from '%s'  successfully.\n", fName);

		fclose(fileReader);
		break;

		//s to save the list to a file (function implemented for you).

	case 's':
		printf("Please enter the filename: ");
		fgets(fName, 100, stdin);

		//FILE *fopen(const char *filename, const char *mode);
		//get rid of endline characters
		if (fName[strlen(fName) - 1] == '\n') {
			fName[strlen(fName) - 1] = 0;
		}

		//w+ - open for reading and writing (overwrite file)
		FILE *fileWriter = fopen(fName, "w+");
		listSave(list, fileWriter);
		printf("The list was saved to the file: '%s' Successfully.\n", fName);

		fclose(fileWriter);
		break;

		//a to add a new task to the list.

	case 'a':
		printf("Please enter the task description: ");
		fgets(desc, 100, stdin);
		/*
		char  *temp= strchr(desc, '\n');
		if (temp)
			*temp = '\0';
		
		*/
		if (desc[strlen(desc) - 1] == '\n') 
			desc[strlen(desc) - 1] = '\0';
		

		printf("Please enter the task priority (0-999): ");
		fgets(fPriority, 100, stdin);
		if (fName[strlen(fName) - 1] == '\n') 
			fName[strlen(fName) - 1] = '\0';
		
		sscanf(fPriority, "%d", &priority);
		/*
		int myInt;
		int result = scanf("%d", &priority);

			while (fgetc(stdin) != '\n');

*/

		Task *task = taskNew(priority, desc);
		dyHeapAdd(list, task, taskCompare);
		printf("The task '%s' has been added to the list.\n", desc);
		printf("\n");
		break;

		//g to get the first task from the list.

	case 'g':
		if (dySize(list) == 0) {
			printf("Your to-do list is empty!\n");
		}
		else {
			printf("Your first task is: %s\n", ((struct Task *)dyHeapGetMin(list))->name);
		}

		break;

		//r to remove the first task from the list.

	case 'r':
		if (dySize(list) == 0) {
			printf("Your to-do list is empty!\n");
		}
		else {
			struct Task* tempTask = (struct Task*)dyHeapGetMin(list);
			
			printf("Your first task '%s' has been removed from the list.\n", tempTask->name);
			
			dyHeapRemoveMin(list, taskCompare);
			taskDelete(tempTask);
		}
		printf("\n");
		break;

	case 'p':
		if (dySize(list) == 0) 
			printf("Your to-do list is empty!\n");
		else 
			listPrint(list);

		break;

	case 'e':
		printf("GoodByte!\n");
		break;
	}

	//free to avoid memory leak
	
	free(desc);
	free(fName);
}

int main()
{
    // Implement
    printf("\n\n** TO-DO LIST APPLICATION **\n\n");
    DynamicArray* list = dyNew(8);
    char command = ' ';
    do
    {
        printf("Press:\n"
               "'l' to load to-do list from a file\n"
               "'s' to save to-do list to a file\n"
               "'a' to add a new task\n"
               "'g' to get the first task\n"
               "'r' to remove the first task\n"
               "'p' to print the list\n"
               "'e' to exit the program\n"
        );
        command = getchar();
        // Eat newlines
        while (getchar() != '\n');
        handleCommand(list, command);
    }
    while (command != 'e');
 /* free dynamically allocated List pointers in array to avoid memory leaks */
         /* Fix it */

    dyDelete(list);
    return 0;
}