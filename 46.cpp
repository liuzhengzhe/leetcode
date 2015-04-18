#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &num){
        ret.push_back(num);
        for(int i=0;i<num.size();i++){
            for(int j=i+1;j<num.size();j++){
                swap(num[i],num[j]);
                dfs(num);
                swap(num[i],num[j]);
            }            
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        
        dfs(num);
        return ret;
    }
};
int main(){
    Solution s;

    vector<vector<int> > a;
    vector<int> b;
    b.push_back(1);
    a.push_back(b);
    s.permute(b);
    return 0;
}