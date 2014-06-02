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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > data;
        if(!root) return data;
        deque<TreeNode *> deq;
        deq.push_back(root);
        int level = 1;
        vector<int> tmp;
        tmp.push_back(root->val);
        data.insert(data.begin(), tmp);
        while(deq.size() > 0) {
            TreeNode *n = deq[0];
            deq.pop_front();
            --level;
            if(n->left) deq.push_back(n->left);
            if(n->right) deq.push_back(n->right);
            if(level == 0) {
                level = deq.size();
                vector<int> tmp;
                for(int i = 0; i < deq.size(); i++)
                    tmp.push_back(deq[i]->val);
                if(tmp.size() > 0)
                    data.insert(data.begin(), tmp);
            }
        }
        return data;
    }
};