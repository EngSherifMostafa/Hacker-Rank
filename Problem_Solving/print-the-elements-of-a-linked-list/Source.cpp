#include <iostream>

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void printLinkedList(SinglyLinkedListNode* head) {  
    for(auto cursor = head ; cursor != NULL ; cursor = cursor->next)
        std::cout << cursor->data << std::endl;

    /*using recursion
    if(head == NULL) return;
    std::cout << head->data << std::endl;
    printLinkedList(head->next);*/
}
