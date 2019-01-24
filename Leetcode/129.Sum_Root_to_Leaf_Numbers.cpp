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
    vector<int> res_vec;
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
            return 0;
        int sum = 0;
        traverse(root, sum);
        int result = 0;
        for(int i=0; i<res_vec.size(); ++i)
            result += res_vec[i];
        return result;
        
    }
    
    void traverse(TreeNode* root, int sum){
        
        if(root->left != NULL && root->right != NULL){
            traverse(root->left, root->val + sum*10);
            traverse(root->right, root->val + sum*10);
        }
        else if(root->left != NULL && root->right == NULL){
            traverse(root->left, root->val + sum*10);
        }
        else if(root->left == NULL && root->right != NULL){
            traverse(root->right, root->val + sum*10);
        }
        else{
            sum = root->val + sum*10;
            res_vec.push_back(sum);   
        }
    }
};