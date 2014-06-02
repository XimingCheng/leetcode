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
    int getDepth(TreeNode *root) {
        if(!root) return 0;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        return max(l, r) + 1;
    }
    
    bool isBalanced(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return true;
        int l = getDepth(root->left);
        int r = getDepth(root->right);
        if(abs(l - r) > 1) return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};