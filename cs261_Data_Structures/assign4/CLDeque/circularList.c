/* CS261- Assignment3*/
/* Name: Khandakar Shadid
* Date: 04/302017
* Solution description:Circlular linked list function Definitions.

*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "circularList.h"

// Double link
struct Link
{
	TYPE value;
	struct Link * next;
	struct Link * prev;
};

struct CircularList
{
	int size;
	struct Link* sentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinel's next and prev should point to the sentinel itself.
 */
static void init(struct CircularList* list)
{
	// FIXME: you must write this 
	list->sentinel = (struct link *) malloc(sizeof(struct Link));
	list->sentinel->next = list->sentinel->prev = list->sentinel;
	list->sentinel->value = list->size = 0;

}

/**
 * Creates a link with the given value and NULL next and prev pointers.
 */
static struct Link* createLink(TYPE value)
{
	struct Link * newLink = (struct Link *)malloc(sizeof(struct Link));

	// Create null pointers
	newLink->next = newLink->prev = NULL;
	newLink->value = value;

	// FIXME: you must write this
	return newLink;
}

/**
 * Adds a new link with the given value after the given link and
 * increments the list's size.
 */
static void addLinkAfter(struct CircularList* list, struct Link* link, TYPE value)
{
	struct Link * newLink = createLink(value);
	newLink->next = link->next;
	newLink->prev = link;
	//adjust the beginnging and the end
	newLink->next->prev = newLink;
	newLink->prev->next = newLink;

	list->size++;
}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct CircularList* list, struct Link* link)
{
	assert(list != 0);

    assert(list-> size != 0);

	assert(link != 0);

	link-> prev -> next = link-> next;

	link-> next -> prev = link-> prev;

    free(link);

	list-> size--;

}

/**
 * Allocates and initializes a list.
 */
struct CircularList* circularListCreate()
{
	struct CircularList* list = malloc(sizeof(struct CircularList));
	init(list);
	return list;
}

/**
 * Deallocates every link in the list and frees the list pointer.
 */
void circularListDestroy(struct CircularList* list)
{
	while (circularListIsEmpty(list)) {
		struct Link * temp = list->sentinel->next;
		removeLink(list, temp);
	}

	free(list->sentinel);



	free(list);
}

/**
 * Adds a new link with the given value to the front of the delinkue.
 */
void circularListAddFront(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel, value);

}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void circularListAddBack(struct CircularList* list, TYPE value)
{
	// FIXME: you must write this
	addLinkAfter(list, list->sentinel->prev, value);


}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE circularListFront(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE circularListBack(struct CircularList* list)
{
	// FIXME: you must write this
	return list->sentinel->prev->value;

}

/**
 * Removes the link at the front of the deque.
 */
void circularListRemoveFront(struct CircularList* list)
{
	// FIXME: you must write this
	assert(list != 0);

	assert(list->size != 0);

	removeLink(list, list->sentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void circularListRemoveBack(struct CircularList* list)
{
	// FIXME: you must write this
	removeLink(list, list->sentinel->prev);

}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int circularListIsEmpty(struct CircularList* list)
{
	if (list->size == 0) 
		return 1;
	
	return 0;
}

/**
 * Prints the values of the links in the deque from front to back.
 */
void circularListPrint(struct CircularList* list)
{
	int size = list->size;
	
	struct Link * index = list->sentinel->next;

	while (size !=0) {
		printf("%g, ", index->value);
		index = index->next;
		size--;
		
	}
	printf("\n ");

}

/**
 * Reverses the deque.
 */
void circularListReverse(struct CircularList* list)
{
	struct Link * current = list->sentinel;

	for (int i = 0; i < list->size + 1; i++) {
		struct Link * temp = current->next;
		current->next = current->prev;

		current->prev = temp;
		current = current->next;
	}

}
