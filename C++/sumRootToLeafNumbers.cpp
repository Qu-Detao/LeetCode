/*
Given a binary tree containing digits from 0-9 only, 
each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which 
represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        return sumNumbers(root, 0);
    }
    
private:
    int sumNumbers(TreeNode* root, int x){
        if(root->left == NULL && root->right == NULL)
            return 10 * x + root->val;
        int val = 0;
        if(root->left)
            val += sumNumbers(root->left, 10 * x + root->val);
        if(root->right)
            val += sumNumbers(root->right, 10 * x + root->val);
        return val;
    }
};

/*
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        queue<TreeNode*> nodeQueue;
        queue<int> sumQueue;
        nodeQueue.push(root);
        sumQueue.push(root->val);
        while(!nodeQueue.empty()){
            TreeNode* curNode = nodeQueue.front();
            nodeQueue.pop();
            int curSum = sumQueue.front();
            sumQueue.pop();
            if(curNode->left == NULL && curNode->right == NULL)
                sum += curSum;

            if(curNode->right){
                nodeQueue.push(curNode->right);
                sumQueue.push(10 * curSum + curNode->right->val);
            }
            if(curNode->left){
                nodeQueue.push(curNode->left);
                sumQueue.push(10 * curSum + curNode->left->val);
            }
        }
        return sum;
    }
};
*/
