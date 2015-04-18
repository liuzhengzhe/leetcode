 #include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int binary(int* a,int start,int end,int t){
        int mid=(start+end)/2;
        if(end-start==1){
            if(a[start]==t){
                return start;
            }
            else{
                return -1;
            }
        }
        if(end==start){
            return -1;
        }
        if(t==a[mid]){
            return mid;
        }
        else if(t<a[mid]){
            return binary(a,start,mid,t);
        }
        else{
            return binary(a,mid,end,t);
        }
        
        
    }
    int search(int A[], int n, int target) {
        int cut=-1;
        int prin=A[0];
        for(int i=0;i<n-1;i++){
            if(A[i]>A[i+1]){
                cut=i;
                break;
            }
        }
        sort(A,A+n);
        int pos=binary(A,0,n,target);
        
        if(pos==-1){
            return pos;
        }
        if(cut==-1){
            return pos;
        }
        if(target<prin){
            pos+=(cut+1);
            return pos;
        }
        else{
            pos-=(n-(cut+1));
            return pos;
        }
    }
};

int main(){
    Solution s;
    int a[3]={3,5,1};
    s.search(a,3,1);
    return 0;
}