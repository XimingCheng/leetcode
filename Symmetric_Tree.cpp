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
    bool isOk(deque<TreeNode *>& data) {
        if(data.size() == 0) return true;
        int time = data.size() / 2;
        for(int i = 0; i <= time; i++) {
            TreeNode *p1 = data[i];
            TreeNode *p2 = data[data.size() - 1 - i];
            if(!p1 && p2) return false;
            else if(p1 && !p2) return false;
            else if(!p1 && !p2) continue;
            else if(p1->val != p2->val) return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return true;
        deque<TreeNode *> data;
        int level = 1;
        data.push_back(root);
        while(data.size() > 0) {
            TreeNode *p = data[0];
            data.pop_front();
            --level;
            if(p) {
                data.push_back(p->left);
                data.push_back(p->right);
            }
            if(level == 0) {
                level = data.size();
                if(!isOk(data)) return false;
            }
        }
        return true;
    }
};