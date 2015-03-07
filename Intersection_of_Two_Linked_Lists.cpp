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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        int lenA = 0, lenB = 0;
        ListNode* nodeA = headA, *nodeB = headB;
        while (nodeA) {
            lenA++;
            nodeA = nodeA->next;
        }
        while (nodeB) {
            lenB++;
            nodeB = nodeB->next;
        }
        nodeA = headA;
        nodeB = headB;
        if (lenA > lenB) {
            int diff = lenA - lenB;
            while (diff) {
                nodeA = nodeA->next;
                diff--;
            }
        } else {
            int diff = lenB - lenA;
            while (diff) {
                nodeB = nodeB->next;
                diff--;
            }
        }
        while (nodeA) {
            if (nodeA == nodeB) return nodeA;
            nodeA = nodeA->next;
            nodeB = nodeB->next;
        }
        return NULL;
    }
};