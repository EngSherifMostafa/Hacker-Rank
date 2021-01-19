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
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
    typedef SinglyLinkedListNode* node_ptr;
    //reserve new node in heap
    node_ptr new_node = new SinglyLinkedListNode(data);
    
    if(head != NULL) {
        auto cursor = head;
        
        while (cursor->next != NULL)
            cursor = cursor->next;
        
        cursor->next = new_node;
    }
    
    else
        head = new_node;
    
    return head;
}
