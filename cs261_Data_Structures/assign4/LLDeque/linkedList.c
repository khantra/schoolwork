#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

// Double link
struct Link
{
	TYPE value;
	struct Link* next;
	struct Link* prev;
};

// Double linked list with front and back sentinels
struct LinkedList
{
	int size;
	struct Link* frontSentinel;
	struct Link* backSentinel;
};

/**
 * Allocates the list's sentinel and sets the size to 0.
 * The sentinels' next and prev should point to eachother or NULL
 * as appropriate.
 */
static void init(struct LinkedList* list) {
	// FIXME: you must write this
	//Front and Back Centinell need memore to be allocated
		//(add free to delete!)
	list->size = 0;
	list->frontSentinel = (struct Link *) malloc(sizeof(struct Link));
	
	list->backSentinel = (struct Link *)malloc(sizeof(struct Link));
	
	list->frontSentinel->next = list->backSentinel;
	list->backSentinel->prev = list->frontSentinel;
//	printf("list->frontSentinel: %p list->frontSentinel->next(end): %p \nlist->backSentinel: %p  list->backSentinel->prev(start): %p \n", list->frontSentinel, list->frontSentinel->next, list->backSentinel, list->backSentinel->prev);


}


/**
 * Adds a new link with the given value before the given link and
 * increments the list's size.
 */
static void addLinkBefore(struct LinkedList* list, struct Link* link, TYPE value)
{
	// FIXME: you must write this

	assert(link != NULL);
	assert(list != NULL);
	struct Link *newLink = (struct Link*) malloc(sizeof(struct Link));

	newLink->value = value;
	newLink->next = link;
	newLink->prev = link->prev;

	link->prev->next = newLink;
	link->prev = newLink;
	list->size++;
//	printf("linkedListAddFront list->size->size(start): %i \n", list->size);

}

/**
 * Removes the given link from the list and
 * decrements the list's size.
 */
static void removeLink(struct LinkedList* list, struct Link* link)
{
	// FIXME: you must write this
	assert(list != NULL || link != NULL);

	link->prev->next = link->next;

	link->next->prev = link->prev;
	list->size--;
	free(link);

}

/**
 * Allocates and initializes a list.
 */
struct LinkedList* linkedListCreate()
{
	struct LinkedList* newDeque = malloc(sizeof(struct LinkedList));
	init(newDeque);
	return newDeque;
}

/**
 * Deallocates every link in the list including the sentinels,
 * and frees the list itself.
 */
void linkedListDestroy(struct LinkedList* list)
{
	while (!linkedListIsEmpty(list))
	{
		linkedListRemoveFront(list);
	}
	free(list->frontSentinel);
	free(list->backSentinel);
	free(list);
}

/**
 * Adds a new link with the given value to the front of the deque.
 */
void linkedListAddFront(struct LinkedList* list, TYPE value)
{
	assert(list != NULL);
	// FIXME: you must write this
	addLinkBefore(list, list->frontSentinel->next, value);
}

/**
 * Adds a new link with the given value to the back of the deque.
 */
void linkedListAddBack(struct LinkedList* list, TYPE value)
{
	assert(list != NULL);
	// FIXME: you must write this
	addLinkBefore(list, list->backSentinel, value);
}

/**
 * Returns the value of the link at the front of the deque.
 */
TYPE linkedListFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL);
	return list->frontSentinel->next->value;
}

/**
 * Returns the value of the link at the back of the deque.
 */
TYPE linkedListBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL);
	return list->backSentinel->prev->value;
}

/**
 * Removes the link at the front of the deque.
 */
void linkedListRemoveFront(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL || list->size !=0);
	removeLink(list, list->frontSentinel->next);
}

/**
 * Removes the link at the back of the deque.
 */
void linkedListRemoveBack(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL || list->size != 0);
	removeLink(list, list->backSentinel->prev);
}

/**
 * Returns 1 if the deque is empty and 0 otherwise.
 */
int linkedListIsEmpty(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL);
	if (list->size == 0)
		return 1;
	else
		return 0;

}

/**
 * Prints the values of the links in the deque from front to back.
 */
void linkedListPrint(struct LinkedList* list)
{
	// FIXME: you must write this
	assert(list != NULL);
	assert(!linkedListIsEmpty(list));
	struct Link *cur = list->frontSentinel->next;
	assert(cur != 0);
	while (cur != list->backSentinel) {
		printf("%d\n", cur->value);
		cur = cur->next;
	}
}

/**
 * Adds a link with the given value to the bag.
 */
void linkedListAdd(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	linkedListAddFront(list, value);

}

/**
 * Returns 1 if a link with the value is in the bag and 0 otherwise.
 */
int linkedListContains(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	assert(list != NULL);
	assert(!linkedListIsEmpty(list));
	struct Link *cur = list->frontSentinel->next;
	while (cur != list->backSentinel) {
		if (cur->value == value) {
			return 1;
		}
		cur = cur->next;
	}
	return 0;
}

/**
 * Removes the first occurrence of a link with the given value.
 */
void linkedListRemove(struct LinkedList* list, TYPE value)
{
	// FIXME: you must write this
	//iterate through and remove each link from front sentinell to backsentinell
	assert(list != NULL);
	assert(!linkedListIsEmpty(list));
//printf("%d \n",!linkedListContains(list, value));
struct Link *index = list->frontSentinel->next; //first item
while (index != list->backSentinel) {
	if (index->value == value) {
		break;

	}
	index = index->next;
}

removeLink(list, index);

}
