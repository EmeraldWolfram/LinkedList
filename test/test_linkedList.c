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
 *  **************
 *  * value = 10 *-------->NULL
 *  **************
 */
void test_createListElement(void){
  ListElement* testElement = createListElement(10);

  TEST_ASSERT_NOT_NULL(testElement);
  TEST_ASSERT_EQUAL(10, testElement->value);
  TEST_ASSERT_NULL(testElement->next);
}

/**
 *  Before:                 After stackAdd:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* value = 10 *--->NULL
 *  ********                ********       **************
 *
 */
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

/**
 *  if Link List is NULL while calling addListLast
 *
 *  tell error
 *  ERROR: Linked List cannot be NULL
 *  Then, jump out directly!
 */
void test_addListLast_NULL_LinkedList_should_return_error(void){
  LinkedList* testLinkedList = NULL;
  ListElement* testElement = createListElement(1);
  addListLast(testLinkedList, testElement);
 
  TEST_ASSERT_NULL(testLinkedList);
}
/**
 *  Before:                 After 1st addListLast:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* value = 1 *--->NULL
 *  ********                ********       **************
 *
 *    After 2nd addListLast
 *     ********--------------------------
 *     * tail *                          \
 *     ********       *************     ************
 *     * head * ----->* value = 1 *--->* value = 2 *----->NULL
 *     ********       *************     ************
 */
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

/**
 *  If the Element add-in is NULL, addListLast tell error and remain the Link List unchanged.
 *
 *  Before:                                        After:
 *
 *  ********---------                              ********-----------
 *  * head *         \                             * head *           \
 *  ********      *************                   ********      *************
 *  * tail * ---> * value = 5 * -----> NULL       * tail * ---> * value = 5 * -----> NULL
 *  ********      *************                   ********      *************
 */
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
/**
 *  Before:                 After 1st addListLast:
 *  ********                ********-------
 *  * head *----->NULL      * head *       \
 *  ********                ********       *************
 *  * tail *----->NULL      * tail * ----->* value = 1 *--->NULL
 *  ********                ********       *************
 *
 *    After 3rd addListFirst
 *     ********-------------------------------------------
 *     * tail *                                           \
 *     ********       ************     ************      *************
 *     * head * ----->* value = 1 *---> * value = 2 *--->* value = 3 *----->NULL
 *     ********       ************     ************      *************
 */
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
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* value = 10 *--->NULL
 *  ********                ********       **************
 *
 */
void test_addListFirst_add_1_Element_in_front(void){
  LinkedList* testList = createLinkedList();
  ListElement* testElement = createListElement(10);
  addListFirst(testList,testElement);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NOT_NULL(testElement);
  TEST_ASSERT_EQUAL(10, testList->head->value);
  TEST_ASSERT_EQUAL(10, testList->tail->value);
  TEST_ASSERT_NULL(testList->tail->next);
  TEST_ASSERT_EQUAL(1,testList->length);
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
 *  Before:                                        After:
 *
 *  ********---------                              ********-----------
 *  * head *         \                             * head *           \
 *  ********      **************                   ********      **************
 *  * tail * ---> * value = 10 * -----> NULL       * tail * ---> * value = 10 * -----> NULL
 *  ********      **************                   ********      **************
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
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* value = 10 *--->NULL
 *  ********                ********       **************
 *
 *    After 2nd addListFirst
 *     ********--------------------------
 *     * tail *                          \
 *     ********       *************    **************
 *     * head * ----->* value = 5 *--->* value = 10 *----->NULL
 *     ********       *************    **************
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
 *  ********                ********       **************
 *  * tail *----->NULL      * tail * ----->* value = 10 *--->NULL
 *  ********                ********       **************
 *
 *    After 3rd addListFirst
 *     ********-------------------------------------------
 *     * tail *                                           \
 *     ********       *************     *************    **************
 *     * head * ----->* value = 2 *---> * value = 5 *--->* value = 10 *----->NULL
 *     ********       *************     *************    **************
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
 *     ********       *************     *************    **************
 *     * head * ----->* value = 2 *---> * value = 5 *--->* value = 10 *----->NULL
 *     ********       *************     *************    **************
 *
 *
 *    After stackRemove
 *     ********--------------------------
 *     * tail *                          \
 *     ********       *************    **************
 *     * head * ----->* value = 5 *--->* value = 10 *----->NULL
 *     ********       *************    **************
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
 *  ********       **************
 *  * tail * ----->* value = 10 *--->NULL
 *  ********       **************
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

/**
 *  if LinkedList is NULL while calling listRemoveFirst
 *
 *  tell error
 *  ERROR: Link List cannot be NULL
 *  Then, return NULL!
 */
void test_listRemoveFirst_NULL_List_remove_Element_should_return_error(void){
  LinkedList* testList = NULL;
  ListElement* removedElement = malloc(sizeof(ListElement));
  removedElement = listRemoveFirst(testList);

  TEST_ASSERT_NULL(testList);
}

/**
 *  If the Stack is empty, stackRemove tell error and return a NULL
 *
 *  Before:                     After:
 *
 *  ********                    ********
 *  * head *-------->NULL       * head *-------->NULL
 *  ********                    ********
 *  * tail *-------->NULL       * tail *-------->NULL
 *  ********                    ********
 *
 *                              Return NULL
 */
void test_listRemoveFirst_given_EmptyLinkedList_should_display_error_and_return_NULL_Element(void){
  LinkedList* testList = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));

  removedElement = listRemoveFirst(testList);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NULL(removedElement);
  TEST_ASSERT_EQUAL(0,testList->length);
}
/**
 *    Before
 *     ********-------------------------------------------
 *     * tail *                                           \
 *     ********       **************     *************    *************
 *     * head * ----->* value = 10 *---> * value = 5 *--->* value = 2 *----->NULL
 *     ********       **************     *************    *************
 *
 *
 *    After stackRemove
 *     ********--------------------------
 *     * tail *                          \
 *     ********       **************    **************
 *     * head * ----->* value = 10 *--->* value = 5 *----->NULL
 *     ********       **************    **************
 */
 
 
void test_listRemoveLast_given_LinkedList_with_3_Element_should_return_removed_element(void){
  LinkedList* testList = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));
  ListElement* testElement_1 = createListElement(10);
  ListElement* testElement_2 = createListElement(5);
  ListElement* testElement_3 = createListElement(2);
  addListLast(testList,testElement_1);
  addListLast(testList,testElement_2);
  addListLast(testList,testElement_3);

  removedElement = listRemoveLast(testList);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(testElement_2);
  TEST_ASSERT_NOT_NULL(testElement_3);
  TEST_ASSERT_NOT_NULL(removedElement);
  TEST_ASSERT_EQUAL(2, removedElement->value);
  TEST_ASSERT_NULL(removedElement->next);
  TEST_ASSERT_EQUAL(10, testList->head->value);
  TEST_ASSERT_EQUAL(5, testList->tail->value);
  TEST_ASSERT_NULL(testList->tail->next);
  TEST_ASSERT_EQUAL(2,testList->length);
}

/**
 *  Before:    
 *  ********-------
 *  * head *       \
 *  ********       **************
 *  * tail * ----->* value = 10 *--->NULL
 *  ********       **************
 *
 *   After
 *     ******** ----->NULL
 *     * tail *
 *     ******** 
 *     * head * ----->NULL
 *     ********
 */
void test_listRemoveLast_given_LinkedList_with_1_Element_should_return_removed_element(void){
  LinkedList* testList = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));
  ListElement* testElement_1 = createListElement(10);
  addListLast(testList,testElement_1);

  removedElement = listRemoveLast(testList);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NOT_NULL(testElement_1);
  TEST_ASSERT_NOT_NULL(removedElement);
  TEST_ASSERT_EQUAL(10, removedElement->value);
  TEST_ASSERT_NULL(removedElement->next);
  TEST_ASSERT_NULL(testList->head);
  TEST_ASSERT_NULL(testList->tail);
  TEST_ASSERT_EQUAL(0,testList->length);
}

/**
 *  If the Linked List is empty, listRemoveLast tell error and return a NULL
 *
 *  Before:                     After:
 *
 *  ********                    ********
 *  * head *-------->NULL       * head *-------->NULL
 *  ********                    ********
 *  * tail *-------->NULL       * tail *-------->NULL
 *  ********                    ********
 *
 *                              Return NULL
 */
void test_listRemoveLast_given_EmptyLinkedList_should_display_error_and_return_NULL_Element(void){
  LinkedList* testList = createLinkedList();
  ListElement* removedElement = malloc(sizeof(ListElement));

  removedElement = listRemoveLast(testList);

  TEST_ASSERT_NOT_NULL(testList);
  TEST_ASSERT_NULL(removedElement);
  TEST_ASSERT_EQUAL(0,testList->length);
}

/**
 *  if LinkedList is NULL while calling listRemoveLast
 *
 *  tell error
 *  ERROR: Link List cannot be NULL
 *  Then, return NULL!
 */
void test_listRemoveLast_NULL_List_remove_Element_should_return_error(void){
  LinkedList* testList = NULL;
  ListElement* removedElement = malloc(sizeof(ListElement));
  removedElement = listRemoveLast(testList);

  TEST_ASSERT_NULL(testList);
}