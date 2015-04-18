class Solution {
public:
    vector<vector<int> > ret;
    void dfs(vector<int> &l, int t,vector<int> al,int start){
        if(t==0){
            ret.push_back(al);
            return;
        }
        for(int i=start;i<l.size();i++){
            if(t>l[i] or t==l[i]){
                al.push_back(l[i]);
                dfs(l,t-l[i],al,i);
                al.erase(al.begin()+al.size()-1);
            }
            else{
                return;
            }
            
        }
    }
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<int> al;
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,al,0);
        return ret;
    }
};