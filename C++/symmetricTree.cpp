/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.

confused what "{1,#,2,3}" means?

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, 
where '#' signifies a path terminator where no node exists below.

Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".
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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        return isSymmetric(root->left, root->right);   
    }
    
private:
    bool isSymmetric(TreeNode* p, TreeNode* q){
        if(p == NULL && q == NULL)  
            return true;
        else if(p == NULL || q == NULL)
            return false;
        
        if(p->val != q->val)
            return false;
        
        return isSymmetric(p->left, q->right) && isSymmetric(p->right, q->left);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        
        stack<TreeNode*>  nodeStack;
        nodeStack.push(root->left);
        nodeStack.push(root->right);
        
        TreeNode *leftNode, *rightNode;
        while(!nodeStack.empty()){
            leftNode = nodeStack.top();
            nodeStack.pop();
            rightNode = nodeStack.top();
            nodeStack.pop();
            
            if(leftNode == NULL && rightNode == NULL)
                continue;
            if(leftNode == NULL || rightNode == NULL)
                return false;
            if(leftNode->val != rightNode->val)
                return false;
            
            nodeStack.push(leftNode->left);
            nodeStack.push(rightNode->right);
            nodeStack.push(leftNode->right);
            nodeStack.push(rightNode->left);
        }
        return true;
    }
};