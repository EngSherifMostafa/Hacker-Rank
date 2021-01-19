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
void reversePrint(SinglyLinkedListNode* head) {
    auto cursor = head;
    vector<int> reverse_data;
    
    while (cursor != nullptr) {
        reverse_data.push_back(cursor->data);
        cursor = cursor->next;
    }
    
    std::copy(reverse_data.rbegin(), reverse_data.rend(), std::ostream_iterator<int>(std::cout, "\n"));
}
