/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path 
from the root node down to the nearest leaf node.
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
    int minDepth(TreeNode* root) {
        if (root == NULL){
            return 0;
        } else if (root->right == NULL || root->left == NULL){
            return max(minDepth(root->left), minDepth(root->right)) + 1;
        } else {
            return min(minDepth(root->left), minDepth(root->right)) + 1;
        }
    }
};

/*
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int depth = 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while(!nodeQueue.empty()){
            depth++;
            int numNode = nodeQueue.size();
            for(int i = 0; i < numNode; ++i){
                TreeNode* curNode = nodeQueue.front();

                if(curNode ->left == NULL && curNode->right == NULL)
                    return depth;
                    
                if(curNode->left)  
                    nodeQueue.push(curNode->left);
                if(curNode->right)
                    nodeQueue.push(curNode->right);
                
                nodeQueue.pop();
            }
        }
    }
};
*/
