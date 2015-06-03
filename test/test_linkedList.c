#include "unity.h"
#include "linkedList.h"
#include "listElement.h"
#include "addList.h"
#include <stdio.h>

void setUp(void){}

void tearDown(void){}
	
void test_Linking_of_Create_LinkedList_ListElement_and_AddList_Functions(void){
	printf("\n\ntest_Linking_of_Create_LinkedList_ListElement_and_AddList_Functions\n");
	LinkedList* myTestList = createLinkedList();
	ListElement* first = createListElement(5);
			
		myTestList->head = first;
		addList(myTestList,8);
		TEST_ASSERT_NULL(myTestList->tail->next);
} //This test make sure the error not causes by linking

void test_LinkedList_With_Single_Node_Print_First_Node_and_Tail_Pointing_Last_Node_Storing__1(void){
	printf("\n\ntest_LinkedList_With_Single_Node_Print_First_Node_and_Tail_Pointing_Last_Node_Storing__1\n");
	LinkedList* myTestList = createLinkedList();

		addList(myTestList,1);
		TEST_ASSERT_EQUAL(1,myTestList->tail->value);
}

void test_LinkedList_With_Three_Node_Print_Nodes_Value_Print_Node_3_5_7(void){
	printf("\n\ntest_LinkedList_With_Three_Node_Print_Nodes_Value_Print_Node_3_5_7\n");
	LinkedList* myTestList = createLinkedList();
		
		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		
		TEST_ASSERT_NULL(myTestList->tail->next);
}

void test_LinkedList_With_Three_empty_Node_Print_Nodes_Value_Print_Node_0_0_0(void){
	printf("\n\ntest_LinkedList_With_Three_empty_Node_Print_Nodes_Value_Print_Node_0_0_0\n");
	LinkedList* myTestList = createLinkedList();
		
		addList(myTestList,0);
		addList(myTestList,0);
		addList(myTestList,0);
		
		TEST_ASSERT_NULL(myTestList->tail->next);
}


void test_LinkedList_With_Four_Node_last_Node_Value_is_9_by_Checking_with_Tail(void){
	printf("\n\ntest_LinkedList_With_Four_Node_last_Node_Value_is_9_by_Checking_with_Tail\n");
	LinkedList* myTestList = createLinkedList();

		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		addList(myTestList,9);
		TEST_ASSERT_EQUAL(9,myTestList->tail->value);
}

void test_LinkedList_With_Four_Node_last_Node_Value_is_9_by_Checking_from_Head_to_Last_Node(void){
	printf("\n\ntest_LinkedList_With_Four_Node_last_Node_Value_is_9_by_Checking_from_Head_to_Last_Node\n");
	LinkedList* myTestList = createLinkedList();
	
		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		addList(myTestList,9);
		TEST_ASSERT_EQUAL(9,myTestList->head->next->next->next->value);
}

void test_LinkedList_With_Four_Node_and_Get_Second_Node_Value_equal_3(void){
	printf("\n\ntest_LinkedList_With_Four_Node_and_Get_Second_Node_Value_equal_3\n");
	LinkedList* myTestList = createLinkedList();

		addList(myTestList,1);
		addList(myTestList,3);
		addList(myTestList,5);
		addList(myTestList,7);
		TEST_ASSERT_EQUAL(3,myTestList->head->next->value);
}


