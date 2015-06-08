#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int cur,int k,vector<int> &v,int n,int t){
        if(cur==k+1){
            ret.push_back(v);
            return;
        }
        for(int i=t+1;i<=n-(k-cur);i++){
            v.push_back(i);
            dfs(cur+1,k,v,n,i);
            v.pop_back();
        }
        return;
    }
    vector<vector<int> > combine(int n, int k) {
        vector<int> v;
        dfs(1,k,v,n,0);
        return ret;
    }
};
int main(){
    Solution s;
    s.combine(4, 2);
    return 0;
}