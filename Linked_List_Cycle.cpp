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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return false;
        if(!head->next) return false;
        ListNode *pFast = head->next->next, *pSlow = head->next;
        while(pFast && pSlow && pFast != pSlow) {
            if(pFast->next && pFast->next->next) pFast = pFast->next->next;
            else return false;
            if(pSlow->next) pSlow = pSlow->next;
            else return false;
        }
        if(pFast == pSlow) return true;
        else return false;
    }
};