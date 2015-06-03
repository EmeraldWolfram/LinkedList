#include "linkedList.h"
#include "listElement.h"
#include <stdlib.h>
#include <malloc.h>

/**
 * createLinkedList
 *	Calling the function will generate an empty Linked List and return it	
 *
 *	As the linked list created was empty, both head and tail point to NULL
 *
 * Words:
 *	1. newList		a new linked list object that is empty
 *
 */


LinkedList* createLinkedList(){
	LinkedList* newList = malloc(sizeof(ListElement));
	
	newList-> head	= NULL;
	newList-> tail	= NULL;
	
	return newList;
}
