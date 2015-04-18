#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<string> > ret;
    vector<string> map;
    bool check(int x,int y,int n,vector<string> map){
        for(int i=0;i<x;i++){
            if(map[i][y]=='Q'){
                return 0;
            }
        }
        for(int i=x-1,j=y-1;i>=0 and j>=0;i--,j--){
            if(map[i][j]=='Q'){
                return 0;
            }
        } 
        for(int i=x-1,j=y+1;i>=0 and j<n;i--,j++){

            if(map[i][j]=='Q'){
                return 0;
            }
            
        }
        return 1;
    }
    bool dfs(int x,int n,vector<string> &map){
        if(map[0][1]=='Q' and map[1][0]=='Q'){
            int xxxxxx=1;
        }
        if(x==n){
            ret.push_back(map);
            return 1;
        }
        for(int y=0;y<n;y++){
            map[x][y]='Q';
            if(check(x,y,n,map)==1){
                dfs(x+1,n,map);
            }
            map[x][y]='.';
        }
        
            

        
        //return 0;
    }
    vector<vector<string> > solveNQueens(int n) {
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            map.push_back(s);
            
        }
        dfs(0,n,map);
        return ret;
    }
};
int main(){
    Solution s;
    s.solveNQueens(2);
    return 0;
}