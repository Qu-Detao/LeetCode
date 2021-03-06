/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;
        ListNode *node1 = head, *node2 = head;
        while(n--){
            node1 = node1->next;
        }
        if(node1 == NULL)
            return head->next;
        while(node1->next){
            node1 = node1->next;
            node2 = node2->next;
        }
        node2->next = node2->next->next;
        return head;
    }
};
