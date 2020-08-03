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
    ListNode* removeElements(ListNode* head, int v) {
        ListNode * ans = new ListNode{0};
        ans->next = head;
        ListNode * pre = ans, *t = ans->next, *temp = nullptr;
        while (t){
            if (t->val == v){
                temp = t;
                pre->next = t->next;
                t = t->next;
                delete temp;
            }
            else pre = t, t = t->next;
        }
        return ans->next;
    }
};
