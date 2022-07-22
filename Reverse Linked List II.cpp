Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and 
return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Solution:

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(head==NULL or head->next==NULL)
          return head;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* c=dummy;
        ListNode* prev=NULL;
      for(int i=0;i<left;i++)
        {
            prev=c;
            c=c->next;
            
        }
          ListNode* prevr=prev;
          ListNode* curr=c;
         
      for(int i=left;i<=right;i++)
        {
            ListNode* frwd=curr->next;
            curr->next=prevr;
            prevr=curr;
            curr=frwd;
                
        }  
        prev->next=prevr;
        c->next=curr;
     
        
        return dummy->next;

    }
};
