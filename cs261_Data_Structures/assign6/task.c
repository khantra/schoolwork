/*
 * CS 261 Assignment 5
 * Name: 
 * Date: 
 */

#include "task.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * Creates a new task with the given priority and name.
 * @param priority
 * @param name
 * @return  The new task.
 */
Task* taskNew(int priority, char* name)
{
    // FIXME: implement
	Task *newTask = malloc(sizeof(Task));
	//newTask->name = name; //not strings
	//The strcpy() function copies the string pointed to by s2 (including the terminating null byte)
	//into the array pointed to by s1.

	strcpy(newTask->name, name);
	
	newTask->priority = priority;

	return newTask;
}

/**
 * Frees a dynamically allocated task.
 * @param task
 */
void taskDelete(Task* task)
{
    free(task);
}

/**
 * Casts left and right to Task pointers and returns
 * -1 if left's priority < right's priority,
 *  1 if left's priority > right's priority,
 *  0 if left's priority == right's priority.
 * @param left  Task pointer.
 * @param right  Task pointer.
 * @return 
 */
int taskCompare(void* left, void* right)
{
	int priority = 0;
    // FIXME: implement
	Task* newLeft = (Task*)left;
	Task* newRight = (Task*)right;

	

	if (newLeft->priority < newRight->priority) 
		priority = -1;

	else if (newLeft->priority > newRight->priority) 
		priority = 1;


	return priority;
}

/**
 * Prints a task as a (priority, name) pair.
 * @param value  Task pointer.
 */
void taskPrint(void* value)
{
    Task* task = (Task*)value;
    printf("(%d, %s)", task->priority, task->name);
}
