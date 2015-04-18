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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;   
        for(int i=0;i<n;i++){
            fast=fast->next;
        }
        if(fast==NULL){
            return head->next;
        }
        while(fast->next!=NULL){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode *dele=slow->next;
        slow->next=dele->next;
        free(dele);
        
        return head;
        
    }
};