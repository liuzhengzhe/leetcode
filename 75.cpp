#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    void sortColors(int A[], int n) {
        int p1=0;
        int p2=n-1;
        for(int i=0;i<=p2;){
            if(A[i]==0){
                swap(A[p1],A[i]);
                p1++;
            }
            if(A[i]==2){
                swap(A[p2],A[i]);
                p2--;
            }
            else{
                i++;
            }
        }
    }
};
int main(){
    Solution s;
    int A[3]={1,2,0};
    s.sortColors(A,3);
    return 0;
}