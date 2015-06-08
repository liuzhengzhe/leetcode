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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* Head=new ListNode(0);
        Head->next=head;
        ListNode *l1=Head;
        ListNode *l2=Head;
        for(int i=0;i<m-1;i++){
            l1=l1->next;
        }
        for(int j=0;j<n;j++){
            l2=l2->next;
        }
        ListNode* l7=l2->next;
        ListNode* l3=l1->next;
        ListNode* l4=l3;
        ListNode* l5;
        ListNode* l6;
       
        l5=l3->next;
        while(l5!=l7){
            l6=l5->next;
            l5->next=l3;
            l3=l5;
            l5=l6;
            
        }
        l1->next=l2;
        l4->next=l7;
        return Head->next;
        
    }
};