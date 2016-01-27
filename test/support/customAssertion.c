#include "customAssertion.h"
#include "unity.h"
#include <stdio.h>
#include <stdlib.h>


//**********************************************************************************************
void customTestAssertListElement(ListElement* expcElm, ListElement* actElm, int lineNumber){
  if(!actElm && expcElm)
    CUSTOM_TEST_FAIL(lineNumber, "Expected element was 0x%X but actual was NULL", expcElm);
  
  if(actElm && !expcElm)
    CUSTOM_TEST_FAIL(lineNumber, "Expected NULL element but actual was 0x%X", actElm);
  
  if(actElm != expcElm)
    CUSTOM_TEST_FAIL(lineNumber, "Expected element was 0x%X but actual was 0x%X", expcElm, actElm);
}

/************************************************************************************************
 * compare the address of every list elements and the number of elements contained between two list.
 ************************************************************************************************/
void customTestAssertLinkedList(LinkedList* expcList, LinkedList* actList, int lineNumber){
  
  int i = 1;
  if(!expcList->head && !actList->head)
    return;
  
  if(!expcList->head && actList->head)
    CUSTOM_TEST_FAIL(lineNumber, "Expected the list was NULL actual was 0x%X.", actList );

  if(expcList->head && !actList->head)
    CUSTOM_TEST_FAIL(lineNumber, "Expected the list was 0x%X actual was NULL.", expcList );

  if(expcList->length != actList->length)
    CUSTOM_TEST_FAIL(lineNumber, "Expected the number of elements in list was %d actual was %d.", expcList->length, actList->length);

  ListElement* tempExpectedElem = expcList->head;
  ListElement* tempActualElem = actList->head;
  
  while(tempExpectedElem && tempActualElem){
    if(tempExpectedElem->value != tempActualElem->value)
      CUSTOM_TEST_FAIL(lineNumber, "Expected the [%d] elements was %d actual was %d.", i, tempExpectedElem, tempActualElem);

    tempExpectedElem = tempExpectedElem->next;
    tempActualElem = tempActualElem->next;
    
    i++;
  }
} 
//*******************************************************************************************
