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
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !(head->next)) return head;
        // O(n^2)
        ListNode * front = new ListNode{}, * pre = head, * cur;
        front->next = head;
        ListNode * p, * c;
        while (pre->next){
            p = front, c = front->next, cur = pre->next;
            while (c->val < cur->val) p = c, c = c->next;
            if (c == cur){
                pre = pre->next;
                continue;
            }
            pre->next = cur->next;
            cur->next = c;
            p->next = cur;
        }

        return front->next;
    }
};
