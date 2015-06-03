#ifndef listElement_H
#define listElement_H

/**
 * ListElement
 *
 *	ListElement type object contain:
 *		1. an integer
 *		2. a pointer pointing to the next ListElement object
 *	
 *	ListElement type object is basically a node that can extend to
 *	to store more value when needed.
 *
 *	It extend by pointing to another ListElement object.
 *	If no more node behind, the pointer point to NULL
 *
 */


typedef struct inElement{
	int value;
	struct inElement* next;
}ListElement;

ListElement* createListElement(int value);

#endif // listElement_H
