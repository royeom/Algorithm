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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);
        
        TreeNode *temp1, *temp2;
        while(!st.empty()){
            temp1 = st.top();
            st.pop();
            temp2 = st.top();
            st.pop();
            if(temp1 == NULL && temp2 == NULL) continue;
            if(temp1 == NULL || temp2 == NULL) return false;
            if(temp1->val != temp2->val) return false;
            
            st.push(temp1->left);
            st.push(temp2->right);
            st.push(temp1->right);
            st.push(temp2->left);
        }
        return true;
    }
};