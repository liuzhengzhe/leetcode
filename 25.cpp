 #include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *reverse(ListNode* head){
        ListNode* cu=head;
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        cu=cu->next;
        ListNode* la=head;
        while(cu!=NULL){
            ListNode* ne=cu->next;
            cu->next=la;
            la=cu;
            cu=ne;
            
        }
        head->next=NULL;
        return la;
    }
    ListNode *reverseKGroup(ListNode *head, int k) {
        int cnt=0;
        int first=1;
        ListNode* cu=head;
        ListNode* ret=NULL;
        ListNode* originhead=NULL;
        if(head==NULL){
            return NULL;
        }
        while(cu->next!=NULL){
            cnt++;
            cu=cu->next;
            if(cnt==k-1){
                ListNode* nextfirst=cu->next;
                if(first==0){
                    originhead->next=cu;
                }
                cu->next=NULL;
                ListNode* newhead=reverse(head);
                if(first==1){
                    ret=newhead;
                }
                first=0;
                cnt=0;
                originhead=head;
                head=nextfirst;
                cu=head;
                originhead->next=cu;
                if(cu==NULL){
                    break;
                }
                
            }
        }
        if(first==1){
            return head;
        }
        else{
            return ret;
        }
    }
};
int main(){
    Solution s;
    ListNode a(1);
    ListNode* p=&a;
    ListNode a2(2);
    ListNode* p2=&a2;
    p->next=p2;
    ListNode a3(3);
    ListNode* p3=&a3;
    p2->next=p3;
    ListNode a4(4);
    ListNode* p4=&a4;
    p3->next=p4;
    s.reverseKGroup(p,2);
    return 0;
}