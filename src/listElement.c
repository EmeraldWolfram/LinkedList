#include "listElement.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * createListElement
 *
 *	Calling the function will generate a ListElement's object and return it.
 *	ListElement type object contain:
 *		1. an integer
 *		2. a pointer to the next ListElement object
 *
 *	ListElement type object is basically a node that can extend to store more value
 *
 * Words:
 *	1. inValue		integer argument brought in to store in the listElement object
 *	2. newNode		new created node that store the "inValue"
 *
 */


ListElement* createListElement(int inValue){
	ListElement* newNode = malloc(sizeof(ListElement*));
	
	newNode->value = inValue;
	newNode->next = NULL;
	
//printf("created node with %d",(newNode->value));
	return newNode;
}