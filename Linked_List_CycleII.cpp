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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return NULL;
        if(!head->next) return NULL;
        ListNode *pFast = head->next->next, *pSlow = head->next;
        while(pFast && pSlow && pFast != pSlow) {
            if(pFast->next && pFast->next->next) pFast = pFast->next->next;
            else return NULL;
            if(pSlow->next) pSlow = pSlow->next;
            else return NULL;
        }
        if(pFast == pSlow) {
            ListNode * p1 = pFast;
            ListNode * p2 = head;
            while(p1 != p2) {
                p1 = p1->next;
                p2 = p2->next;
            }
            return p1;
        }
        else return NULL;
    }
};