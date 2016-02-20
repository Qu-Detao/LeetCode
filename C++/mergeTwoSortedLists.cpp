/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL)  return l2;
        else if(l2 == NULL) return l1;
        
        ListNode *head = l1->val <= l2->val ? l1 : l2;
        ListNode *p = l1->val <= l2->val ? l2 : l1;
        ListNode *cur = head, *temp;
        while(cur->next && p){
            if(cur->next->val <= p->val){
                cur = cur->next;
            } else {
                temp = cur->next;
                cur->next = p;
                cur = cur->next;
                p = temp;
            }
        }
        cur->next = p;
        
        return head;
    }
};

/*
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) return l2;
        if (l2 == NULL) return l1;
        if (l1->val <= l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
*/