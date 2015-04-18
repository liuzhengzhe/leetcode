#include <iostream>
using namespace std;
#include <string>
#include <cmath>
class Solution {
public:
    int uniquePaths(int m, int n) {
        int **d= new int*[m];
        for(int i=0;i<m;i++){
            d[i]=new int[n];
        }
        for(int i=0;i<m;i++){
            d[i][0]=1;
        }
        for(int j=0;j<n;j++){
            d[0][j]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                d[i][j]=d[i-1][j]+d[j-1][i];
            }
        }
        return d[m-1][n-1];
        
    }
};
int main(){
    Solution s;
    cout<<s.uniquePaths(3,7);
    return 0;
}