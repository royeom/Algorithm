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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL||head->next==NULL)
            return true;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        slow->next=reverseList(slow->next);
        
        slow=slow->next;
        
        while(slow!=NULL){
            if(head->val != slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* res=NULL;
        ListNode* temp=NULL;
        while(head!=NULL){
            temp=head->next;
            head->next=res;
            res=head;
            head=temp;
        }
        return res;
    }
};