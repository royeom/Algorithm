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
    vector<string> res_vec;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return res_vec;
        string temp = "";
        traverse(root, temp);
        return res_vec;
    }
    
    void traverse(TreeNode* root, string temp){
        temp += to_string(root->val);
        if(root->left != NULL && root->right != NULL){
            temp += "->";
            traverse(root->left, temp);
            traverse(root->right, temp);
        }
        else if(root->left == NULL && root->right != NULL){
            temp += "->";
            traverse(root->right, temp);
        }
        else if(root->left != NULL && root->right == NULL){
            temp += "->";
            traverse(root->left, temp);
        }
        else
            res_vec.push_back(temp);
    }
};