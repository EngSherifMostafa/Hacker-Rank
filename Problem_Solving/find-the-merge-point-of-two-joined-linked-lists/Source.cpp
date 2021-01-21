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
int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    auto cursor1 = head1;
    auto cursor2 = head2;

    while (cursor1 != cursor2) {
        //cursor1
        if(cursor1->next == null)
            cursor1 = head2;
			
		else
            cursor1 = cursor1->next;
		
        //cursor2
        if(cursor2->next == null)
            cursor2 = head1;
        
		else
            cursor2 = cursor2->next;
			
    }
	
    return cursor1->data;
}