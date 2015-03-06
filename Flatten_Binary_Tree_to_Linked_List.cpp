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
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        if (root->left) {
            TreeNode *backup = root->right;
            root->right = root->left;
            root->left = NULL;
            TreeNode *node = root->right;
            while (1) {
                if (!node->right) break;
                node = node->right;
            }
            node->right = backup;
        }
    }
};