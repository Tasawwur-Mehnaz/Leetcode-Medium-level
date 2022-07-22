Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]


Solution:
//Created two new linked lists for greater and equal value and one for smaller values and then joined them accordingly
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL || head->next==NULL)
            return head;
        
        ListNode* d1=new ListNode(-1);
        ListNode* d2=new ListNode(-1);
        ListNode* t1=d1;
        ListNode* t2=d2;
        ListNode* curr=head;
        while(curr)
        {
            if(curr->val<x)
            {
               ListNode* temp=new ListNode(curr->val);
                t1->next=temp;
                t1=t1->next;
            }
            else
            {
                ListNode* temp=new ListNode(curr->val);
                t2->next=temp;
                t2=t2->next;
            }
            curr=curr->next;
        }
        if(d1->next!=NULL)
        { 
            t1->next=d2->next;
            return d1->next;
        }
        return d2->next;
    }
};
