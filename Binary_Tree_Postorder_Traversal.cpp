/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> data;
        if(!root) return data;
        stack<TreeNode*> s1, s2;
        s1.push(root);
        while(!s1.empty())
        {
            TreeNode* p = s1.top();
            s1.pop();
            s2.push(p);
            if(p->left) s1.push(p->left);
            if(p->right) s1.push(p->right);
        }
        while(!s2.empty())
        {
            TreeNode* p = s2.top();
            s2.pop();
            data.push_back(p->val);
        }
        return data;
    }
};