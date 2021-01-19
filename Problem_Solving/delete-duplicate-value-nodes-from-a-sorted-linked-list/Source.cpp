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
 void delete_node (SinglyLinkedListNode* previous, SinglyLinkedListNode* del_node) {
     //if del_node == tail
     if (del_node->next == nullptr) {
        del_node = nullptr;
        previous->next = nullptr;
     }
     
     //other
     else {
        previous->next = del_node->next;
        del_node = nullptr;
     }
 }

SinglyLinkedListNode* removeDuplicates(SinglyLinkedListNode* head) {
    auto temp = head;

    while (temp && temp->next) {
        while (temp->data == temp->next->data) {
            delete_node(temp, temp->next);
            if(!temp->next)
                break;
        }
        temp = temp->next;
    }
    return head;
}