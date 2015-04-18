#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int> > ret;
    bool findvalue(vector<int> num,int start,int end,int t){
        for(int i=start;i<end;i++){
            if(num[i]==t){
                return 1;
            }
        }
        return 0;
    }
    void dfs(vector<int> &num,int cur){
        if(cur==num.size()){
            ret.push_back(num);
            return;
        }
        for(int i=cur;i<num.size();i++){
            if(i==cur or findvalue(num,cur,i,num[i])==0){
                swap(num[i],num[cur]);
                dfs(num,cur+1);
                swap(num[i],num[cur]);
            }
                
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(),num.end());
        dfs(num,0);
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(-1);
    a.push_back(-1);
    a.push_back(-1);
    a.push_back(3);
    s.permuteUnique(a);
    return 0;
}