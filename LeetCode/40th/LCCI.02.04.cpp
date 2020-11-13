class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode * smallHead = new ListNode{}; 
        ListNode * bigHead = new ListNode{};
        ListNode * small = smallHead, * big = bigHead, * cur = head;

        while (cur) {
            if (cur->val < x) {
                small->next = cur, small = small->next;
            } else {
                big->next = cur, big = big->next;
            }
            cur = cur->next;
        }
        small->next = bigHead->next;
        big->next = NULL;

        return smallHead->next;
    }
};