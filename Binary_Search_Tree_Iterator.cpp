/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    vector<int> data;
    int index;
    
    void parseData(TreeNode* root) {
        if (!root) return;
        if (root->left) parseData(root->left);
        data.push_back(root->val);
        if (root->right) parseData(root->right);
    }
    
    BSTIterator(TreeNode *root) {
        index = 0;
        parseData(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index < data.size();
    }

    /** @return the next smallest number */
    int next() {
        return data[index++];
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */