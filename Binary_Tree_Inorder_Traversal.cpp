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
    vector<int> inorderTraversal(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<int> data;
        if(!root) return data;
        vector<int> dataLeft, dataRight;
        dataLeft = inorderTraversal(root->left);
        dataRight = inorderTraversal(root->right);
        copy(dataLeft.begin(), dataLeft.end(), back_inserter(data));
        data.push_back(root->val);
        copy(dataRight.begin(), dataRight.end(), back_inserter(data));
        return data;
    }
};