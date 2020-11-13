class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode * cur = head;
        while (cur && cur->next) {
            ListNode * nxt = cur->next;
            swap(cur->val, nxt->val);
            cur = nxt->next;
        }
        return head;
    }
};