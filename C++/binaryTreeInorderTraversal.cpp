/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        stack<TreeNode*> nodeStack;
        TreeNode* curNode = root;
        while(!nodeStack.empty() || curNode){
            if(curNode){
                nodeStack.push(curNode);
                curNode = curNode->left;
            }else{
                curNode = nodeStack.top();
                nodeVals.push_back(curNode->val);
                nodeStack.pop();
                curNode = curNode->right;
            }
        }
    
        return nodeVals;
    }
};

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return nodeVals;
        inorderTraversal(root->left);
        nodeVals.push_back(root->val);
        inorderTraversal(root->right);
    
        return nodeVals;
    }

private:
    vector<int> nodeVals;
};
*/

/*
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodeVals;
        stack<TreeNode*> nodeStack;
        if (root)
            nodeStack.push(root);
        TreeNode* curNode;
        while (!nodeStack.empty()) {
            curNode = nodeStack.top();
            if (curNode->left) {
                nodeStack.push(curNode->left);
                curNode->left = NULL;
            }
            else {
                nodeVals.push_back(curNode->val);
                nodeStack.pop();
                if (curNode->right)
                    nodeStack.push(curNode->right);
            }
        }
    
        return nodeVals;
    }
};
*/
