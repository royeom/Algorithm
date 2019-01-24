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
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        while(1){
            if(head->val == 99999)
                return true;
            if(head->next == NULL)
                return false;
            head->val = 99999;
            head = head->next;
        }
        
    }
};