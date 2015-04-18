 #include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binary(int* a,int start,int end,int t){
        int mid=(start+end)/2;
        if(a[mid]==t){
            return mid;
        }
        if(start==end){
            if(a[start]<t){
                return start+1;
            }
            if(a[start]>t){
                return start;
            }
        }
        if(end-start==1){
            if(a[start]<t){
                return start+1;
            }
            if(t<a[start]){
                return start;
            }
        }
        if(a[mid]>t){
            return binary(a,0,mid,t);
        }
        if(a[mid]<t){
            return binary(a,mid,end,t);
        }
    }
    int searchInsert(int A[], int n, int target) {
        return binary(A,0,n,target);
    }
};
int main(){
    Solution s;
    int a[2]={1,3};
    s.searchInsert(a,2,4);
    return 0;
}