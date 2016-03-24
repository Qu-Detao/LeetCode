/*
Given a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideVal;
        vector<TreeNode*> lastLevel;
        vector<TreeNode*> curLevel;
        if (root)
            curLevel.push_back(root);
        while (!curLevel.empty()) {
            rightSideVal.push_back(curLevel[curLevel.size() - 1]->val);
            swap(lastLevel, curLevel);
            curLevel.clear();
            for (int i = 0; i < lastLevel.size(); ++i) {
                if (lastLevel[i]->left)
                    curLevel.push_back(lastLevel[i]->left);
                if (lastLevel[i]->right)
                    curLevel.push_back(lastLevel[i]->right);
            }
        }
    
        return rightSideVal;
    }
};

/*
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideVal;
        rightSideView(root, 1, rightSideVal);
        return rightSideVal;
    }

private:
    void rightSideView(TreeNode* root, int level, vector<int>& rightSideVal) {
        if (root == NULL)   return;
        if (rightSideVal.size() < level)
            rightSideVal.push_back(root->val);
        rightSideView(root->right, level + 1, rightSideVal);
        rightSideView(root->left, level + 1, rightSideVal);
    }
};
*/
