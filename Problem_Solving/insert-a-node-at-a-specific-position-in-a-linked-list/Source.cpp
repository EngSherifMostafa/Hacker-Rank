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
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    typedef SinglyLinkedListNode* node_ptr;
    auto previous = head;
    node_ptr new_node = new SinglyLinkedListNode(data);
    
    for(auto index = 0 ; index < position - 1 ; index++)
        previous = previous->next;
        
    auto cursor = previous->next;
    
    previous->next = new_node;
    new_node->next = cursor;

    return head;
}
