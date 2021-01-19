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
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {

    typedef SinglyLinkedListNode* node_ptr;

    node_ptr new_node = new SinglyLinkedListNode(data);
    
    if(llist != NULL)
        new_node->next = llist;
        
    llist = new_node;
    return new_node;
}
