/*
Given a binary tree, flatten it to a linked list in-place.
For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
Hints:
If you notice carefully in the flattened tree, 
each node's right child points to the next node of a pre-order traversal.
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
    void flatten(TreeNode* root) {
        TreeNode* curNode = root;
        while(curNode){
            if(curNode->left){
                TreeNode* preNode = curNode->left;
                while(preNode->right)
                    preNode = preNode->right;
                preNode->right = curNode->right;
                curNode->right = curNode->left;
                curNode->left = NULL;
            }
            curNode = curNode->right;
        }
    }
};

/*
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*> nodeStack;
        TreeNode* curNode = root;
        while(curNode){
            if(curNode->right)
                nodeStack.push(curNode->right);
            if(curNode->left)
                curNode->right = curNode->left;
            else{
                if(!nodeStack.empty()){
                    curNode->right = nodeStack.top();
                    nodeStack.pop();
                }
            }
            curNode->left = NULL;
            curNode = curNode->right;
        }
    }
};
*/
