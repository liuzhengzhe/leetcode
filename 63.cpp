#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        int **d= new int*[m];
        for(int i=0;i<m;i++){
            d[i]=new int[n];
        }
        int flag=0;
        for(int i=0;i<m;i++){
            if(obstacleGrid[i][0]==1){
                flag=1;
            }
            if(flag==0){
                d[i][0]=1;
            }
            else{
                d[i][0]=0;
            }
        }
        flag=0;
        for(int j=0;j<n;j++){
            if(obstacleGrid[0][j]==1){
                flag=1;
            }
            if(flag==0){
                d[0][j]=1;
            }
            else{
                d[0][j]=0;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0){
                    d[i][j]=d[i-1][j]+d[i][j-1];
                }
                else{
                    d[i][j]=0;
                }
            }
        }
        return d[m-1][n-1];        
    }
};
int main(){
    Solution s;
    vector<vector<int> > a;
    int q[6]={1,0,0,0,0,0};
    int w[6]={0,1,0,1,0,0};
    vector<int> b(&q[0],&q[5]);
    vector<int> c(&w[0],&w[5]);
    a.push_back(b);
    a.push_back(c);
    cout<<s.uniquePathsWithObstacles(a);
    return 0;
}