#include <iostream>
#include <vector>

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    vector<int> vect;
    auto cursor1 = head1;
    auto cursor2 = head2;

    while(cursor1) {
        vect.push_back(cursor1->data);
        cursor1 = cursor1->next;
    }

    while(cursor2) {
        vect.push_back(cursor2->data);
        cursor2 = cursor2->next;
    }
    
    std::sort(vect.begin(), vect.end());
    
    SinglyLinkedList llist;
    
    for(auto itr = vect.begin() ; itr != vect.end() ; itr++)
        llist.insert_node(*itr);
    
    return llist.head;
}