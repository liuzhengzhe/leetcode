 #include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int binary(int* a,int start,int end,int t){
        int mid=(start+end)/2;
        if(end<=start){
            return -1;
        }
        if(end-start==1){
            if(t!=a[start]){
                return -1;
            }
            else{
                return start;
            }

        }
        if(mid==0){
            if(a[mid]==t){
                return 0;
            }
            else{
                return -1;
            }
            
        }
        
        if(t==a[mid] and t>a[mid-1]){
            return mid;
        }
        if(t==a[mid]){
            return binary(a,start,mid,t);
        }
        if(t<a[mid]){
            return binary(a,start,mid,t);
        }
        else{
            return binary(a,mid,end,t);
        }
    }
    int binary2(int* a,int start,int end,int t){
        int mid=(start+end)/2;
        if(end<=start){
            return -1;
        }
        if(end-start==1){
            if(a[start]==t){
                return start;
            }
            else{
                return -1;
            }
        }
        if(mid==end){
            if(a[mid]==t){
                return 0;
            }
            else{
                return -1;
            }
            
        }
        
        if(t==a[mid] and t<a[mid+1]){
            return mid;
        }
        if(t==a[mid]){
            return binary2(a,mid,end,t);
        }
        if(t<a[mid]){
            return binary2(a,start,mid,t);
        }
        else{
            return binary2(a,mid,end,t);
        }
    }
    vector<int> searchRange(int A[], int n, int target) {
        int start=binary(A,0,n,target);
        int end=binary2(A,0,n,target);
        vector<int> ret;
        ret.push_back(start);
        ret.push_back(end);
        return ret;
    }
};
int main(){
    Solution s;
    int a[3]={1,2,2};
    s.searchRange(a,3,2);
    return 0;
}