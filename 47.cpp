#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &num,int cur){
        if(cur==num.size()){
            ret.push_back(num);
            return;
        }
        for(int i=cur;i<num.size();i++){
            swap(num[i],num[cur]);
            dfs(num,cur+1);
            swap(num[i],num[cur]);
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        
        dfs(num,0);
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(1);
    s.permute(a);
    return 0;
}