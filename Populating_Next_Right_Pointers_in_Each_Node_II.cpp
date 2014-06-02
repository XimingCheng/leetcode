/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!root) return;
        TreeLinkNode *p = root;
        while(p) {
            TreeLinkNode *tmp = p;
            while(p) {
                TreeLinkNode *start = p->left;
                if(p->left && p->right) {
                    p->left->next = p->right;
                    start = p->right;
                }
                else if(p->right)
                    start = p->right;
                else if(p->left)
                    start = p->left;
                else {
                    p = p->next;
                    continue;
                }
                while(p->next && (!p->next->left && !p->next->right))
                    p = p->next;
                if(p->next && p->next->left)
                    start->next = p->next->left;
                else if(p->next && p->next->right)
                    start->next = p->next->right;
                else
                    start->next = NULL;
                p = p->next;
            }
            while(tmp && !tmp->left && !tmp->right)
                tmp = tmp->next;
            if(!tmp) return;
            p = tmp->left ? tmp->left : tmp->right;
        }
    }
};