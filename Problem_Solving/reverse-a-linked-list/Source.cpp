#include <iostream>
#include <stack>
/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* reverse(SinglyLinkedListNode* head) {

    if(head == nullptr)
    return nullptr;
    
    stack<int> stk;
    auto cursor = head;
    
    while (cursor != nullptr) {
        stk.push(cursor->data);
        cursor = cursor->next;
    }
        
    cursor = head;
    while (stk.size() != 0) {
        cursor->data = stk.top();
        stk.pop();
        cursor = cursor->next;
    }
    
    return head;
}