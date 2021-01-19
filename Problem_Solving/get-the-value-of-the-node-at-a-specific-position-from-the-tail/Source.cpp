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
int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    
    //point to tail
    auto tail = head;    
    while (tail->next)
        tail = tail->next;
    
    for (int index = 0; index < positionFromTail ; index++) {
        auto previous = head;        
        while (previous->next != tail)
            previous = previous->next;
            
        tail = previous;
    }
    
    return tail->data;
}