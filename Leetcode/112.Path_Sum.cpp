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
    bool flag = false;
    
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        traverse(root, sum);
        return flag;   
    }
    
    void traverse(TreeNode* root, int res){
        
        if(root->left != NULL && root->right != NULL){
            traverse(root->left, res - root->val);
            traverse(root->right, res - root->val);
        }
        else if(root->left == NULL && root->right != NULL)
            traverse(root->right, res - root->val);
        else if(root->left != NULL && root->right == NULL)
            traverse(root->left, res - root->val);
        else
            if(res - root->val == 0) flag = true;
    }
};