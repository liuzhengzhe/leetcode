#include <iostream>
using namespace std;

struct ListNode {
    int val;
      ListNode *next;
      ListNode(int x){ 
        this->val=x;
        this->next=NULL;
      };
  };
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* l1=head;
        ListNode* l2=head;
        int tmp;
        int rep=0;
        while(l2!=NULL){
            if(rep==1){
                if(l2->val==tmp){
                    l2=l2->next;
                }
                else{
                    rep=0;
                    if(l1==head){
                        head=l2;
                        l1=l2;
                    }
                    else{
                        l1->next=l2;
                    }
                }
            }
            else{
                
                if(l2!=head and l2->val==tmp){
                    rep=1;
                }
                l1=l2;
                l2=l2->next;
                tmp=l2->val;
            }
            
            
        }
        return head;
    }
};
int main(){
    Solution s;
    ListNode* head= new ListNode(1);
    s.deleteDuplicates(head);
    return 0;
}