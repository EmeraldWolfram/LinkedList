#ifndef linkedList_H
#define linkedList_H
#include "listElement.h"

/**
 * LinkedList
 *	
 *	Object of LinkedList's type contain:
 *		1. head
 *		2. tail
 *	where the head always point to the first node of the linked list and
 *	the tail always point to the last node of the linked list
 *
 *	Both head and tail are ListElement object that point to another ListElement
 *	object but head and tail does not store value.
 *
 *	If the linked list is empty, both head and tail point to NULL
 *
 */


typedef struct{
	ListElement* head;
	ListElement* tail;
}LinkedList;

LinkedList* createLinkedList();

#endif // linkedList_H
