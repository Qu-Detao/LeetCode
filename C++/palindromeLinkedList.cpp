/*
Given a singly linked list, determine if it is a palindrome.

Follow up:
Could you do it in O(n) time and O(1) space?
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
    bool isPalindrome(ListNode* head) {
        ListNode *rev = NULL, *fast = head, *tail;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *temp = rev;
            rev = head;
            head = head->next;
            rev->next = temp;
        }
        tail = fast ? head->next : head;
    
        while (rev) {
            if (rev->val != tail->val)
                return false;
            ListNode* temp = head;
            head = rev;
            rev = rev->next;
            head->next = temp;
            tail = tail->next;
        }
        return true;
    }
};
