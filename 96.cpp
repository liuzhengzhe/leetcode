#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        int* d=new int[n+1];
        if(n==0 or n==1){
            return 1;
        }
        for(int i=0;i<=n;i++){
            d[i]=0;
        }
        d[0]=1;
        d[1]=1;
        for(int i=2;i<=n;i++){
            for(int j=0;j<i;j++){
                d[i]+=d[j]*d[i-j-1];
            }
        }
        return d[n];
    }
};
int main()
{
    Solution s;
    s.numTrees(2);
    return 0;
}