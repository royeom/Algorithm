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
    vector<int> pathVec;
    
    int pathSum(TreeNode* root, int sum) {
        
        if(root == NULL) return 0;
        
        pathVec.push_back(root->val);
        int count = pathSum(root->left, sum) + pathSum(root->right, sum);
        int temp = 0;
        for(int i = pathVec.size() - 1; i>=0; --i){
            temp += pathVec[i];
            if(temp == sum)
                count++;
        }
        pathVec.pop_back();
        
        return count;
    }
};