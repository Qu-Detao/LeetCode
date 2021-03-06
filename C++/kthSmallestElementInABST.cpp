/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth 
smallest frequently? How would you optimize the kthSmallest routine?

Hint:
1. Try to utilize the property of a BST.
2. What if you could modify the BST node's structure?
3. The optimal runtime complexity is O(height of BST).
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> nodeStack;
        TreeNode* curNode = root;
        while(!nodeStack.empty() || curNode){
            while(curNode){
                nodeStack.push(curNode);
                curNode = curNode->left;
            }
            
            curNode = nodeStack.top();
            if(--k == 0)
                return curNode->val;
            nodeStack.pop();
            curNode = curNode->right;
        }
    }
};
