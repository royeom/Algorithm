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
        return DFS(root);
    }
    
    int DFS(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left == NULL) return 1 + DFS(root->right);
        if(root->right == NULL) return 1 + DFS(root->left);
        return 1 + min(DFS(root->left), DFS(root->right));
    }
};