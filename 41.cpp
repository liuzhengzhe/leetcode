 #include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i=0;i<n;i++){
            if(A[i]>0 and A[i]<n){
                int tmp=A[i];
                A[i]=A[tmp-1];
                A[tmp-1]=tmp;
            }
        }
        int j=-1;
        for(int i=0;i<n;i++){
            if((i+1)!=A[i]){
                j=i+1;
                break;
            }
        }
        if(j==-1){
            j=A[n-1]+1;
        }
        return j;
    }
};
int main(){
    Solution s;
    int a[6]={-1,4,2,1,9,10};
    s.firstMissingPositive(a,6);
    return 0;
}