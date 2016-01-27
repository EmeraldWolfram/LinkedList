#ifndef customAssertion_H
#define customAssertion_H

#include "unity.h"
#include "LinkedList.h"

// ... can represent any arguement.
#define CUSTOM_TEST_FAIL(lineNo, msg, ...)                                                        \
                {                                                                                 \
                char buffer[256];                                                                 \
                sprintf(buffer, msg, ## __VA_ARGS__);                                             \
                UNITY_TEST_FAIL(lineNo,buffer);                                                   \
                }

#define TEST_ASSERT_LIST_ELEMENT(expcElm, actElm);                   \
          customTestAssertListElement(expcElm, actElm, __LINE__);
          
#define TEST_ASSERT_LINKED_LIST(expcList, actList);                    \
          customTestAssertLinkedList(expcList, actList, __LINE__);

void customTestAssertListElement(ListElement* expcElm, ListElement* actElm, int lineNumber);
void customTestAssertLinkedList(LinkedList* expcList, LinkedList* actList, int lineNumber);


#endif // customAssertion_H
