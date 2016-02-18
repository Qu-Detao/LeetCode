/*
Reverse a singly linked list.

Hint:
A linked list can be reversed either iteratively or recursively.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /* iteratively */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *cur = head, *tmp;
        while(cur){
            tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};

/* recursively */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return node;
    }
};