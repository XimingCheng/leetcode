/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return NULL;
        int curVal = head->val;
        ListNode *p = head->next, *pPre = head;
        while(p) {
            if(p->val == curVal) {
                pPre->next = p->next;
                delete p;
                p = pPre->next;
            } else {
                pPre = p;
                p = p->next;
                curVal = pPre->val;
            }
        }
        return head;
    }
};