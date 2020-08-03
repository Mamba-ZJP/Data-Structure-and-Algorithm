/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !(head->next)) return head;
        ListNode * pre = head, * t = head->next->next, * temp, *evenstart = head->next;
        int cnt = 0;
        while (t != NULL){
            temp = pre->next;
            pre->next = t;
            // printf("%d,%d ",pre->val, t->val);
            // cout << 1;
            pre = temp;
            t = t->next;
            cnt++;
        }

        if (cnt % 2){
            pre->next->next = evenstart; 
            pre->next = nullptr;
        } 
        else pre->next = evenstart;


        return head;
    }
};
