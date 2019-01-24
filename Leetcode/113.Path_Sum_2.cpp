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
    vector<vector<int>> res_vec;
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root == NULL) return res_vec;
        vector<int> temp;
        traverse(root, sum, temp);
        return res_vec;
    }
    
    void traverse(TreeNode* root, int res, vector<int> temp){
        temp.push_back(root->val);
        if(root->left != NULL && root->right != NULL){
            traverse(root->left, res - root->val, temp);
            traverse(root->right, res - root->val, temp);
        }
        else if(root->left == NULL && root->right != NULL)
            traverse(root->right, res - root->val, temp);
        else if(root->left != NULL && root->right == NULL)
            traverse(root->left, res - root->val, temp);
        else
            if(res - root->val == 0){
                res_vec.push_back(temp);
            } 
    }
};