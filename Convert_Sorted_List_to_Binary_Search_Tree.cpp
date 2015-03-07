/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *buildTree(vector<int>& data, int begin, int end) {
        if (begin > end) return NULL;
        if (begin == end) return new TreeNode(data[begin]);
        int mid = begin + (end - begin)/2;
        TreeNode *node = new TreeNode(data[mid]);
        node->left = buildTree(data, begin, mid - 1);
        node->right = buildTree(data, mid + 1, end);
        return node;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        vector<int> data;
        ListNode *node = head;
        while(node) {
            data.push_back(node->val);
            node = node->next;
        }
        return buildTree(data, 0, data.size() - 1);
    }
};