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

// none recursive solution for inorder
class Solution_None_Recursive {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> data;
        stack<TreeNode*> miniStack;
        TreeNode* node = root;
        while(node || !miniStack.empty())
        {
            while(node)
            {
                miniStack.push(node);
                node = node->left;
            }
            if(!miniStack.empty())
            {
                node = miniStack.top();
                miniStack.pop();
                data.push_back(node->val);
                node = node->right;
            }
        }
        return data;
    }
};
