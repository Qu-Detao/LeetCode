/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (root == NULL)
            return paths;
        stack<TreeNode*> nodeStack;
        nodeStack.push(root);
        stack<string> strStack;
        strStack.push(to_string(root->val));
        while (!nodeStack.empty()) {
            TreeNode* curNode = nodeStack.top();
            nodeStack.pop();
            string curStr = strStack.top();
            strStack.pop();
            if (curNode->left == NULL && curNode->right == NULL) {
                paths.push_back(curStr);
                continue;
            }
            if (curNode->right) {
                nodeStack.push(curNode->right);
                strStack.push(curStr + "->" + to_string(curNode->right->val));
            }
            if (curNode->left) {
                nodeStack.push(curNode->left);
                strStack.push(curStr + "->" + to_string(curNode->left->val));
            }
        }
    
        return paths;
    }
};
