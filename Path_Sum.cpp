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
    void preOrder(TreeNode* node, vector<int>& path, int sum, bool& bHave)
    {
        if(!node) return;
        path.push_back(node->val);
        if(!node->left && !node->right)
        {
            int path_sum = 0;
            for(int i = 0; i < path.size(); i++)
                path_sum += path[i];
            if(path_sum == sum)
                bHave = true;
        }
        preOrder(node->left, path, sum, bHave);
        if(node->left)
            path.pop_back();
        preOrder(node->right, path, sum, bHave);
        if(node->right)
            path.pop_back();
    }
    
    bool hasPathSum(TreeNode *root, int sum) {
        vector<int> path;
        bool bHave = false;
        preOrder(root, path, sum, bHave);
        return bHave;
    }
};