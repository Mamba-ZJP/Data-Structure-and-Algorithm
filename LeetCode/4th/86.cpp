class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
       //创建两个结点，用于保存<x的值和>=x的值
        ListNode *before=new ListNode(0);
        ListNode *after=new ListNode(0);
        
        ListNode *p1=before,*p2=after;
        if(!head)
        return head;
        
        while(head)
        {
            if(head->val<x)
            {
                p1->next=head;
                p1=p1->next;
                head=head->next;
            }
            else
            {
                p2->next=head;
                p2=p2->next;
                head=head->next;
            }
        }
        
        p2->next=NULL;
        p1->next=after->next;
        return before->next;
    }
};
