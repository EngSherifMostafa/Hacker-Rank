#include <iostream>

// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) {
    //empty list
    if(head == nullptr)
        return head;
    
    //delete head node
    else if(position == 0) {
        auto del_node = head;
        head = head->next;
        delete del_node;
    }
    
    //delete node from 2-node to n node
    else {
        //hold previous node             
        auto previous = head;        
        for(auto index = 0 ; index < position - 1 ; index++)
            previous = previous->next;
        
        //hold delete node
        auto del_node = previous->next;

        //there are reminder nodes after delete node
        if(previous->next->next != nullptr)
            previous->next = del_node->next;
        
        delete del_node;
    }
    
    return head;
}
