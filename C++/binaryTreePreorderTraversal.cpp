/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        stack<TreeNode*> nodeStack;
        if(root) nodeStack.push(root);
        TreeNode *curNode;
        while(!nodeStack.empty()){
            curNode = nodeStack.top();
            nodeStack.pop();
            nodeVals.push_back(curNode->val);
            if(curNode->right)
                nodeStack.push(curNode->right);
            if(curNode->left)
                nodeStack.push(curNode->left);
        }
        return nodeVals;
    }
};


/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == NULL)
            return nodeVals;
        nodeVals.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    
        return nodeVals;
    }
    
private:
    vector<int> nodeVals;
};
*/
