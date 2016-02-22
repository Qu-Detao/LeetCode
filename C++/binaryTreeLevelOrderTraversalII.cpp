/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int d = getDepth(root);
        vector<vector<int>> retVal(d, vector<int> {});
        getLevelOrder(retVal, root, d - 1);
        
        return retVal;
    }

private:
    int getDepth(TreeNode* root){
        if(root == NULL)    return 0;
        
        int leftDepth = getDepth(root->left);
        int rightDepth = getDepth(root->right);
        
        return max(leftDepth, rightDepth) + 1;
    }
    
    void getLevelOrder(vector<vector<int>> &retVal, TreeNode* root, int d){
        if(root == NULL)    return;
        retVal[d].push_back(root->val);
        getLevelOrder(retVal, root->left, d - 1);
        getLevelOrder(retVal, root->right, d - 1);
    }
};

/*
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> retVal;
        if(root == NULL)    return retVal;

        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            vector<int> curLevel;
            int numNode = nodeQueue.size();
            for(int i = 0; i < numNode; ++i){
                TreeNode* cur = nodeQueue.front();
                nodeQueue.pop();
                curLevel.push_back(cur->val);
                if(cur->left)  nodeQueue.push(cur->left);
                if(cur->right) nodeQueue.push(cur->right);
            }
            retVal.push_back(curLevel);
        }
        reverse(retVal.begin(), retVal.end());
        return retVal;
    }
};
*/
