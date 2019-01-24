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
    vector<int> res;
    vector<int> preorderTraversal(TreeNode* root) {
        
        preOrder(root);
        return res;
    }
    
    void preOrder(TreeNode* root){
        if(root == NULL)
            return;
        res.push_back(root->val);
        if(root->left != NULL)
            preOrder(root->left);
        if(root->right != NULL)
            preOrder(root->right);
    }
};