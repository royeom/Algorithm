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
    TreeNode* makeBST(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBST(nums, start, mid-1);
        root->right = makeBST(nums, mid+1, end);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return makeBST(nums, 0, nums.size()-1);
    }
};