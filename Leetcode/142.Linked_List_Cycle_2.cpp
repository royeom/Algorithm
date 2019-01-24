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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
            return NULL;
        while(1){
            if(head->val == 99999)
                return head;
            if(head->next == NULL)
                return NULL;
            head->val = 99999;
            head = head->next;
        }   
    }
};