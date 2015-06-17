#include "addList.h"
#include "linkedList.h"
#include "listElement.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * addList
 *	A function that will add a new Node at the last part of the Linked List.
 *
 *	This function track the last node of the linked list and enable 
 *	the tail to point to the last node.
 *
 *	The Ex-last node of the linked list will point to the new created note
 *	whenever this function is called.
 ****************************************************************
 * Eg.																													*
 *		Before calling this function															*
 *		------																										*
 *		*tail* next ... v																					*
 *		------	 		 ------------				-----											*
 *		*head* next> * 6 **node1* next> * 0 *				 							*
 *		------	 		 ------------	  		-----											*
 *									^first node																	*
 *																															*
 *		After calling this function added node2 that store 3			*
 *		------																										*
 *		*tail* next ... ... ... ... ... .. v											*
 *		------	 		 ------------				------------			 -----	*
 *		*head* next> * 6 **node1* next> * 3 **node2* next> * 0 *	*
 *		------	 		 ------------	  		------------			 -----	*	
 ****************************************************************	
 *
 * Define:
 *	currentList			the linked list that adding node into it
 *	tempNode				copy the First node of the brought in linked list, for checking
 *							 		attribute.
 * 	currentNode			the last node of the linked list before calling the function
 *	inValue					the value to be stored in the new created node
 *
 */

