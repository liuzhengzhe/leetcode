 #include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &l, int t,vector<int> al,int start,vector<int> ali){

        if(t==0){
            /*for(int i=0;i<ret.size();i++){
                if(ret[i]==al){
                    return;
                }
            }*/
            ret.push_back(al);
            return;
        }
        for(int i=start;i<l.size();i++){
            if(t>l[i] or t==l[i]){
                if(find(ali.begin(),ali.end(),i)==ali.end()){
                    al.push_back(l[i]);
                    ali.push_back(i);
                    dfs(l,t-l[i],al,i,ali);
                    al.erase(al.begin()+al.size()-1);
                    ali.erase(ali.begin()+ali.size()-1);  
                }
            }
            else{
                return;
            }
            
        }
        return;
    }
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<int> al;
        vector<int> ali;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,al,0,ali);
        return ret;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(1); 
    a.push_back(1); 
    s.combinationSum2(a,1);
    return 0;
}