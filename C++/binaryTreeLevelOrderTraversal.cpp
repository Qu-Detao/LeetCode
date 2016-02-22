/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> retVal;
        if(root == NULL)    return retVal;
        
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            vector<int> curLevel;
            int numNode = nodeQueue.size();
            for(int i = 0; i < numNode; ++i){
                TreeNode* curNode = nodeQueue.front();
                nodeQueue.pop();
                curLevel.push_back(curNode->val);
                if(curNode->left)   nodeQueue.push(curNode->left);
                if(curNode->right)  nodeQueue.push(curNode->right);
            }
            retVal.push_back(curLevel);
        }
        return retVal;
    }
};
