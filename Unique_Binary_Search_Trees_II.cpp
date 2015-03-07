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
    vector<TreeNode *> buildTree(vector<int>& data, int begin, int end) {
        vector<TreeNode *> ret;
        if (begin > end) {
            ret.push_back(NULL);
            return ret;
        }
        if (begin == end) {
            TreeNode *node = new TreeNode(data[begin]);
            ret.push_back(node);
            return ret;
        }
        for (int target = begin; target <= end; target++) {
            vector<TreeNode *> left = buildTree(data, begin, target - 1);
            vector<TreeNode *> right = buildTree(data, target + 1, end);
            for (auto itLeft = left.begin(); itLeft < left.end(); ++itLeft) {
                for (auto itRight = right.begin(); itRight < right.end(); ++itRight) {
                    TreeNode *node = new TreeNode(data[target]);
                    node->left = *itLeft;
                    node->right = *itRight;
                    ret.push_back(node);
                }
            }
        }
        return ret;
    }
    vector<TreeNode *> generateTrees(int n) {
        vector<int> data;
        for (int i = 1; i <= n; i++) data.push_back(i);
        return buildTree(data, 0, data.size() - 1);
    }
};