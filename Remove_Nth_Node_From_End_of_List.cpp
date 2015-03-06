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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (!head) return head;
        ListNode* p1 = head;
        ListNode* p2 = head;
        int time = n;
        while (p2 && time) {
            p2 = p2->next;
            time--;
        }
        if (!p2 && time == 0) return head->next;
        else if (!p2) return head;
        while (p2->next) {
            p2 = p2->next;
            p1 = p1->next;
        }
        ListNode* p = p1->next->next;
        p1->next = p;
        return head;
    }
};