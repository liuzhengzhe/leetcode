 #include <iostream>
using namespace std;
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode* cu=head;
        
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* ret=head->next;
        while(cu->next!=NULL){
            ListNode* sec=cu->next;
            ListNode* ne=sec->next;
            sec->next=cu;
            if(ne==NULL){
                cu->next=NULL;
                break;
            }
            if(ne->next==NULL){
                cu->next=ne;
                break;
            }
            cu->next=ne->next;
            cu=ne;
        }
        return ret;
        
    }
};
int main(){
    Solution s;
    ListNode a(1);
    ListNode* p=&a;
    ListNode a2(2);
    ListNode* p2=&a2;
    p->next=p2;
    s.swapPairs(p);
    return 0;
}