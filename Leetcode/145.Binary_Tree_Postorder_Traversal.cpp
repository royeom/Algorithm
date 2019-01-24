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
    vector<int> postorderTraversal(TreeNode* root) {
        postOrder(root);
        return res;
    }
    
    void postOrder(TreeNode* root){
        if(root == NULL)
            return;
        
        if(root->left != NULL)
            postOrder(root->left);
        
        if(root->right != NULL)
            postOrder(root->right);
        
        res.push_back(root->val);
    }
};