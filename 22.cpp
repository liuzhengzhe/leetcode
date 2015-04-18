#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int n;
    vector<string> ret;    
    void dfs(string tmp,int left,int right){
        if(tmp.length()==2*n){
            ret.push_back(tmp);
            return;
        }
        if(left<n){
            dfs(tmp+'(',left+1,right);
        }
        if(right<left){
            dfs(tmp+')',left,right+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        this->n=n;
        string tmp="";
        dfs(tmp,0,0);

        return ret;
    }
};
int main(){
    Solution s;
    vector<string> ret=s.generateParenthesis(3);
    cout<<ret.size();
    return 0;
}