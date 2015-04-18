#include <iostream>
#include "stdlib.h"
using namespace std;
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        //ListNode ret(0);
        //ListNode* ret2=&ret;
        ListNode* ret=NULL;
        ListNode* ret2=ret;
        int last=0;
        for(;l1!=NULL and l2!=NULL;l1=l1->next,l2=l2->next){
            int value=l1->val+l2->val+last;
            ListNode* tmp=new ListNode(value%10);
            last=value/10;
            if(ret2==NULL){
                //ListNode* ret2=(ListNode*)malloc(sizeof(ListNode));
                //free(ret2);
                ret=tmp;
                ret2=tmp;
            }
            else{
                //ret2->next=(ListNode*)malloc(sizeof(ListNode));
                ret2->next=tmp;
                ret2=ret2->next;
            }

        }
        if(l1!=NULL){
            for(;l1!=NULL;l1=l1->next){
                int value=l1->val+last;
                ListNode* tmp=new ListNode(value%10);
                last=value/10;
                if(ret2==NULL){
                    //ListNode* ret2=(ListNode*)malloc(sizeof(ListNode));
                    ret2=tmp;
                }
                else{
                    //ret2->next=(ListNode*)malloc(sizeof(ListNode));
                    ret2->next=tmp;
                    ret2=ret2->next;
                }
            }
        }
        if(l2!=NULL){
            for(;l2!=NULL;l2=l2->next){
                int value=l2->val+last;
                ListNode* tmp=new ListNode(value%10);
                last=value/10;
                if(ret2==NULL){
                        //ListNode* ret2=(ListNode*)malloc(sizeof(ListNode));
                        ret2=tmp;
                    }
                    else{
                        //ret2->next=(ListNode*)malloc(sizeof(ListNode));
                        ret2->next=tmp;
                        ret2=ret2->next;
                    }     
  
            }
        }
        if(last==1){
            ret2->next=new ListNode(1);
            ret2=ret2->next;
        }
        cout<<(ret->val);
        return ret;
    }

};
int main(){
    Solution s;
    ListNode l1(3);
    ListNode l11(7);
    l1.next=&l11;
    ListNode l2(2);
    ListNode l22(9);
    l2.next=&l22;
    s.addTwoNumbers(&l1,&l2);
}