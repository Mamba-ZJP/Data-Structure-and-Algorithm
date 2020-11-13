class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        vector<int> cur;
        ListNode * t = head;
        while (t) {
            cur.push_back(t->val); t = t->next;
        }
        return cur[cur.size() - k];
    }
};