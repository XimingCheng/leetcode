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
    ListNode *swapPairs(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if(!head) return NULL;
        if(!head->next) return head;
        auto p = head;
        auto q = head->next;
        p->next = q->next;
        q->next = p;
        p->next = swapPairs(p->next);
        return q;
    }
};