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
    ListNode* comb(ListNode *t1,ListNode *t2){
        ListNode head(0);
        ListNode * al=&head;
        for(;t1!=NULL and t2!=NULL;){
            if(t1->val<t2->val){
                al->next=t1;
                t1=t1->next;
                al=al->next;
            }
            else{
                al->next=t2;
                t2=t2->next;
                al=al->next;
            }
        }
        if(t1!=NULL){
            al->next=t1;
        }
        else if(t2!=NULL){
            al->next=t2;
        }
        return head.next;  
    }
    ListNode* dvd(vector<ListNode*> &lists){
        int i=0;
        vector<ListNode*> one;
        vector<ListNode*> two;
        for(;i<lists.size()/2;i++){
            one.push_back(lists[i]);
        }
        for(;i<lists.size();i++){
            two.push_back(lists[i]);
        }
        if(one.size()==0 and two.size()==0){
            return NULL;
        }

        if (one.size()==0){
            return two[0];
        }
        if(two.size()==0){
            return one[0];
        }

       ListNode* l1= dvd(one);
        ListNode *l2= dvd(two);
        return comb(l1,l2);
        
    }
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        return dvd(lists);
    }
};




int main(){
    Solution s;
    vector<ListNode *> inp;
    ListNode a(1);
    ListNode* p=&a;
    inp.push_back(p);
    inp.push_back(p);
    s.mergeKLists(inp);
    return 0;
}