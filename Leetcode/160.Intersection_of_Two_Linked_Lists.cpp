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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* hheadA = headA;
        ListNode* hheadB = headB;
        
        if(headA ==NULL || headB ==NULL)
            return NULL;
        
        while(hheadA!= hheadB){
            hheadA = hheadA->next;
            hheadB = hheadB->next;
            
            if(hheadA == hheadB) return hheadA;
            
            if(hheadA == NULL) hheadA = headB;
            if(hheadB == NULL) hheadB = headA;
        }
        
        return hheadA;
        
    }
};