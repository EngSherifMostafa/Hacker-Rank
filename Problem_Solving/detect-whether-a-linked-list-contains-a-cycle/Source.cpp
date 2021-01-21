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
bool has_cycle(SinglyLinkedListNode* head) {
    if (head == nullptr)
        return 0;
    
    auto slow = head;
    auto fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            return 1;
        }
    }
    
    return 0;
}