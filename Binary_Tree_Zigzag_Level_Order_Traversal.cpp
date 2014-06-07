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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        bool odd = true;
        vector<vector<int> > data;
        if(!root) return data;
        deque<TreeNode *> deq;
        deq.push_back(root);
        int level = 1;
        vector<int> tmp;
        tmp.push_back(root->val);
        data.push_back(tmp);
        odd = !odd;
        while(deq.size() > 0) {
            TreeNode *n = deq[0];
            deq.pop_front();
            --level;
            if(n->left) deq.push_back(n->left);
            if(n->right) deq.push_back(n->right);
            if(level == 0) {
                level = deq.size();
                vector<int> tmp;
                if(odd) {
                    for(int i = 0; i < deq.size(); i++)
                        tmp.push_back(deq[i]->val);
                } else {
                    for(int i = deq.size() - 1; i >= 0; i--)
                        tmp.push_back(deq[i]->val);
                }
                odd = !odd;
                if(tmp.size() > 0)
                    data.push_back(tmp);
            }
        }
        return data;
    }
};
