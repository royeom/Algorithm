/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode* makeBST(vector<int>& nums, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = makeBST(nums, start, mid-1);
        root->right = makeBST(nums, mid+1, end);
        return root;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while(head != NULL){
            nums.push_back(head->val);
            head = head->next;
        }
        return makeBST(nums, 0, nums.size()-1);
    }
};