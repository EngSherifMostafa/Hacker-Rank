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
bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    auto cursor1 = head1;
    auto cursor2 = head2;

    while(cursor1 && cursor2) {       
        if(cursor1->data == cursor2->data) {
            cursor1 = cursor1->next;
            cursor2 = cursor2->next;
        }
        else
            break;
        
        if(cursor1 == nullptr && cursor2 == nullptr)
            return true;
    }
    return false;
}
