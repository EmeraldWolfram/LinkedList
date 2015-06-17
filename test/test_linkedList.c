#include "unity.h"
#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

void setUp(void){}

void tearDown(void){}
	
  /**
 *  createLinkedList like this
 *
 *  ********
 *  * head *-------->NULL
 *  ********
 *  * tail *-------->NULL
 *  ********
 */
void test_Linking_of_Create_LinkedList(void){
	LinkedList* myTestList = createLinkedList();
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NULL(myTestList->head);
	TEST_ASSERT_NULL(myTestList->tail);
  TEST_ASSERT_EQUAL(0,myTestList->length);
}

/**
 *  createListElement like this
 *
 *  *************
 *  * data = 10 *-------->NULL
 *  *************
 */
void test_createListElement(void){
  ListElement* testElement = createListElement(10);

  TEST_ASSERT_NOT_NULL(testElement);
  TEST_ASSERT_EQUAL(10, testElement->value);
  TEST_ASSERT_NULL(testElement->next);
}

void test_addListLast_add_Single_Node_at_Last(void){
	LinkedList* myTestList = createLinkedList();
  ListElement* testElement = createListElement(1);
  
	addListLast(myTestList,testElement);
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement);
	TEST_ASSERT_EQUAL(1,myTestList->tail->value);
	TEST_ASSERT_EQUAL(1,myTestList->head->value);
	TEST_ASSERT_NULL(myTestList->tail->next);
}
void test_addListLast_NULL_LinkedList_should_return_error(void){
  LinkedList* testLinkedList = NULL;
  ListElement* testElement = createListElement(1);
  addListLast(testLinkedList, testElement);
 
  TEST_ASSERT_NULL(testLinkedList);
}

void test_addListLast_add_Two_Node_at_Last(void){
	LinkedList* myTestList = createLinkedList();
  ListElement* testElement_1 = createListElement(1);
  ListElement* testElement_2 = createListElement(2);
  
	addListLast(myTestList,testElement_1);
	addListLast(myTestList,testElement_2);
  
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
	TEST_ASSERT_EQUAL(2,myTestList->tail->value);
	TEST_ASSERT_EQUAL(1,myTestList->head->value);
  TEST_ASSERT_EQUAL_PTR(myTestList->head->next,myTestList->tail);
	TEST_ASSERT_NULL(myTestList->tail->next);
  TEST_ASSERT_EQUAL(2,myTestList->length);
}

void test_addListLast_add_NULL_Element_at_Last_should_return_error(void){
  LinkedList* testList = createLinkedList();
  ListElement* testElement_1 = createListElement(5);
  ListElement* testElement_2 = NULL;
  addListLast(testList,testElement_1);
  addListLast(testList,testElement_2);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NULL(testElement_2);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_EQUAL(5, testList->head->value);
  TEST_ASSERT_NULL(testList->head->next);
  TEST_ASSERT_EQUAL_PTR(testList->head, testList->tail);
  TEST_ASSERT_EQUAL(1,testList->length);
}

void test_addListLast_add_Three_Node_at_Last(void){
	LinkedList* myTestList = createLinkedList();
  ListElement* testElement_1 = createListElement(1);
  ListElement* testElement_2 = createListElement(2);
  ListElement* testElement_3 = createListElement(3);
		
	addListLast(myTestList,testElement_1);
	addListLast(myTestList,testElement_2);
	addListLast(myTestList,testElement_3);
		
  TEST_ASSERT_NOT_NULL(myTestList);
  TEST_ASSERT_NOT_NULL(testElement_1); 
  TEST_ASSERT_NOT_NULL(testElement_2); 
  TEST_ASSERT_NOT_NULL(testElement_3); 
  TEST_ASSERT_EQUAL(1, myTestList->head->value);
  TEST_ASSERT_EQUAL(3, myTestList->tail->value);
	TEST_ASSERT_EQUAL_PTR(myTestList->head->next->next,myTestList->tail);
	TEST_ASSERT_NULL(myTestList->tail->next);
  TEST_ASSERT_EQUAL(3,myTestList->length);
}

/**
 *  Before:                 After stackAdd:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       *************
 *  * tail *----->NULL      * tail * ----->* data = 10 *--->NULL
 *  ********                ********       *************
 *
 */
void test_addListFirst_add_1_Element_in_front(void){
  LinkedList* testStack = createLinkedList();
  ListElement* testElement = createListElement(10);
  addListFirst(testStack,testElement);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NOT_NULL(testElement);
  TEST_ASSERT_EQUAL(10, testStack->head->value);
  TEST_ASSERT_EQUAL(10, testStack->tail->value);
  TEST_ASSERT_NULL(testStack->tail->next);
  TEST_ASSERT_EQUAL(1,testStack->length);
}


/**
 *  if Link List is NULL while calling addListFirst
 *
 *  tell error
 *  ERROR: Linked List cannot be NULL
 *  Then, jump out directly!
 */
void test_addListFirst_NULL_LinkedList_add_1_Element_should_return_error(void){
  LinkedList* testStack = NULL;
  ListElement* testElement = createListElement(10);
  addListFirst(testStack,testElement);

  TEST_ASSERT_NULL(testStack);
}

/**
 *  If the Element add-in is NULL, addListFirst tell error and remain the Link List unchanged.
 *
 *  Before:                                       After:
 *
 *  ********---------                             ********-----------
 *  * head *         \                            * head *           \
 *  ********      *************                   ********      *************
 *  * tail * ---> * data = 10 * -----> NULL       * tail * ---> * data = 10 * -----> NULL
 *  ********      *************                   ********      *************
 */
void test_addListFirst_add_NULL_Element_in_front(void){
  LinkedList* testStack = createLinkedList();
  ListElement* testElement_1 = createListElement(10);
  ListElement* testElement_2 = NULL;
  addListFirst(testStack,testElement_1);
  addListFirst(testStack,testElement_2);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NULL(testElement_2);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_EQUAL(10, testStack->head->value);
  TEST_ASSERT_NULL(testStack->head->next);
  TEST_ASSERT_EQUAL_PTR(testStack->head, testStack->tail);
  TEST_ASSERT_EQUAL(1,testStack->length);
}


/**
 *  Before:                 After 1st addListFirst:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       *************
 *  * tail *----->NULL      * tail * ----->* data = 10 *--->NULL
 *  ********                ********       *************
 *
 *    After 2nd addListFirst
 *     ********--------------------------
 *     * tail *                          \
 *     ********       ************    *************
 *     * head * ----->* data = 5 *--->* data = 10 *----->NULL
 *     ********       ************    *************
 */
void test_addListFirst_add_2_Element_in_front(void){
  LinkedList* testStack = createLinkedList();
  ListElement* testElement_1 = createListElement(10);
  ListElement* testElement_2 = createListElement(5);
  addListFirst(testStack,testElement_1);
  addListFirst(testStack,testElement_2);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
  TEST_ASSERT_EQUAL(5, testStack->head->value);
  TEST_ASSERT_EQUAL(10, testStack->head->next->value);
  TEST_ASSERT_EQUAL_PTR(testStack->head->next, testStack->tail);
  TEST_ASSERT_NULL(testStack->tail->next);
  TEST_ASSERT_EQUAL(2,testStack->length);
}

/**
 *  Before:                 After 1st addListFirst:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       *************
 *  * tail *----->NULL      * tail * ----->* data = 10 *--->NULL
 *  ********                ********       *************
 *
 *    After 3rd addListFirst
 *     ********-------------------------------------------
 *     * tail *                                           \
 *     ********       ************     ************    *************
 *     * head * ----->* data = 2 *---> * data = 5 *--->* data = 10 *----->NULL
 *     ********       ************     ************    *************
 */
void test_addListFirst_add_3_Element_in_front(void){
  LinkedList* testStack = createLinkedList();
  ListElement* testElement_1 = createListElement(10);
  ListElement* testElement_2 = createListElement(5);
  ListElement* testElement_3 = createListElement(2);
  addListFirst(testStack,testElement_1);
  addListFirst(testStack,testElement_2);
  addListFirst(testStack,testElement_3);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
  TEST_ASSERT_NOT_NULL(testElement_3);
  TEST_ASSERT_EQUAL(2, testStack->head->value);
  TEST_ASSERT_EQUAL(5, testStack->head->next->value);
  TEST_ASSERT_EQUAL(10, testStack->tail->value);
  TEST_ASSERT_EQUAL_PTR(testStack->head->next->next, testStack->tail);
  TEST_ASSERT_NULL(testStack->tail->next);
  TEST_ASSERT_EQUAL(3,testStack->length);
}

/**
 *    Before
 *     ********-------------------------------------------
 *     * tail *                                           \
 *     ********       ************     ************    *************
 *     * head * ----->* data = 2 *---> * data = 5 *--->* data = 10 *----->NULL
 *     ********       ************     ************    *************
 *
 *
 *    After stackRemove
 *     ********--------------------------
 *     * tail *                          \
 *     ********       ************    *************
 *     * head * ----->* data = 5 *--->* data = 10 *----->NULL
 *     ********       ************    *************
 *
 */
void test_listRemoveFirst_given_LinkedList_with_3_Element_should_return_LinkedList_with_2_element(void){
  LinkedList* testStack = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));
  ListElement* testElement_1 = createListElement(10);
  ListElement* testElement_2 = createListElement(5);
  ListElement* testElement_3 = createListElement(2);
  addListFirst(testStack,testElement_1);
  addListFirst(testStack,testElement_2);
  addListFirst(testStack,testElement_3);

  removedElement = listRemoveFirst(testStack);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
  TEST_ASSERT_NOT_NULL(testElement_3);
  TEST_ASSERT_NOT_NULL(removedElement);
  TEST_ASSERT_EQUAL(2, removedElement->value);
  TEST_ASSERT_NULL(removedElement->next);
  TEST_ASSERT_EQUAL(5, testStack->head->value);
  TEST_ASSERT_EQUAL(10, testStack->tail->value);
  TEST_ASSERT_NULL(testStack->tail->next);
  TEST_ASSERT_EQUAL(2,testStack->length);
}

/**
 *  Before:    
 *  ********-------
 *  * head *       \
 *  ********       *************
 *  * tail * ----->* data = 10 *--->NULL
 *  ********       *************
 *
 *   After
 *     ******** ----->NULL
 *     * tail *
 *     ******** 
 *     * head * ----->NULL
 *     ********
 */
void test_listRemoveFirst_given_LinkList_with_1_Element_should_return_empty_LinkList(void){
  LinkedList* testStack = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));
  ListElement* testElement_1 = createListElement(10);
  addListFirst(testStack,testElement_1);

  removedElement = listRemoveFirst(testStack);

  TEST_ASSERT_NOT_NULL(testStack);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(removedElement);
  TEST_ASSERT_NULL(testStack->head);
  TEST_ASSERT_NULL(testStack->tail);
  TEST_ASSERT_EQUAL(10,removedElement->value);
  TEST_ASSERT_EQUAL(0,testStack->length);
}
//*********************************CONTINUE HERE
/**
 *  if LinkedList is NULL while calling listRemoveFirst
 *
 *  tell error
 *  ERROR: Link List cannot be NULL
 *  Then, return NULL!
 */
void test_stackRemove_NULL_Stack_remove_Element_should_return_error(void){
  LinkedList* testStack = NULL;
  ListElement* removedElement = malloc(sizeof(ListElement));
  removedElement = listRemoveFirst(testStack);

  TEST_ASSERT_NULL(testStack);
}
