#include "unity.h"
#include "linkedList.h"
#include "listElement.h"
#include "addList.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}
	
void test_Linking_of_Create_LinkedList_ListElement_and_AddList_Functions(void){
	LinkedList* myTestList = createLinkedList();
	ListElement* first = createListElement(5);
			
		myTestList->head = first;
		addList(myTestList,8);
		TEST_ASSERT_NULL(myTestList->tail->next);
} //This test make sure the error not causes by linking

void test_LinkedList_With_Single_Node_Print_First_Node_With_HEAD_TAIL_Storing_1(void){
	LinkedList* myTestList = createLinkedList();
		addList(myTestList,1);
		TEST_ASSERT_EQUAL(1,myTestList->tail->value);
		TEST_ASSERT_EQUAL(1,myTestList->head->value);
		TEST_ASSERT_NULL(myTestList->tail->next);
}


void test_LinkedList_With_Three_0_Node_Print_Nodes_Value_Print_Node_0_0_0(void){
	LinkedList* myTestList = createLinkedList();
		
		addList(myTestList,0);
		addList(myTestList,0);
		addList(myTestList,0);
		
		TEST_ASSERT_EQUAL(0,myTestList->head->next->next->value);
		TEST_ASSERT_EQUAL(0,myTestList->tail->value);
		TEST_ASSERT_NULL(myTestList->tail->next);
}



void test_LinkedList_With_Four_Node_last_Node_Value_is_9(void){
	LinkedList* myTestList = createLinkedList();
	
		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		addList(myTestList,9);
		
		TEST_ASSERT_EQUAL(9,myTestList->head->next->next->next->value);
		TEST_ASSERT_EQUAL(9,myTestList->tail->value);
		TEST_ASSERT_NULL(myTestList->tail->next);
}

void test_LinkedList_With_Four_Node_and_Get_All_Node_Value(void){
	LinkedList* myTestList = createLinkedList();

		addList(myTestList,1);
		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		
		TEST_ASSERT_EQUAL(3,myTestList->head->next->value);
		TEST_ASSERT_EQUAL(5,myTestList->head->next->next->value);
		TEST_ASSERT_EQUAL(7,myTestList->head->next->next->next->value);
		TEST_ASSERT_NULL(myTestList->tail->next);
}


