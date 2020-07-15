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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode{0}, * t = ans;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry) {
            if(l1 != NULL){
                carry += l1->val;
                l1 = l1->next;
            } 
            if(l2 != NULL){
                carry += l2->val;
                l2 = l2->next;
            }
            t->next = new ListNode{carry % 10};
            carry /= 10;
            t = t->next;
        }
        return ans->next;
    }
};
