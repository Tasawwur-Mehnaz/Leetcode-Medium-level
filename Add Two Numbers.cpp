You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]

Solution:

class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        int carry=0;
        ListNode* ans=new ListNode(0);
        ListNode* d=ans;
        while(cur1!=NULL && cur2!=NULL)
        {
            int a=cur1->val;
            int b=cur2->val;
            int sum=a+b+carry;
            carry=sum/10;
            ListNode* t=new ListNode(sum%10);
            d->next=t;
            d=d->next;
            cur1=cur1->next;
            cur2=cur2->next;
            
        }
        while(cur1!=NULL)
        {
            int a=cur1->val;
            int sum=a+carry;
            carry=sum/10;
            ListNode* t=new ListNode(sum%10);
            d->next=t;
            d=d->next;
            cur1=cur1->next;
        }
         while(cur2!=NULL)
        {
            int b=cur2->val;
            int sum=b+carry;
            carry=sum/10;
            ListNode* t=new ListNode(sum%10);
            d->next=t;
            d=d->next;
            cur2=cur2->next;
        }
        if(carry!=0)
        {
            ListNode* t=new ListNode(carry);
            d->next=t;
            d=d->next;
            carry=0;
        }

        return ans->next;
    }
 };
 
 
 Shorter Approach :
 
 class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        int carry=0;
        ListNode* ans=new ListNode(0);
        ListNode* d=ans;
        while(cur1!=NULL || cur2!=NULL)
        {
            int a=cur1?cur1->val:0;
            int b=cur2?cur2->val:0;
            int sum=a+b+carry;
            carry=sum/10;
            ListNode* t=new ListNode(sum%10);
            d->next=t;
            d=d->next;
            cur1=cur1?cur1->next:NULL;
            cur2=cur2?cur2->next:NULL;
            
        }
        if(carry!=0)
        {
            ListNode* t=new ListNode(carry);
            d->next=t;
            d=d->next;
        }

        return ans->next;
    }
};
 
 
 
