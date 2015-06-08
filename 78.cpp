class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int t,int max,vector<int> &v,vector<int> &S){
        ret.push_back(v);
        if(t==S.size()){
            return;
        }
        for(int i=t;i<S.size();i++){
            v.push_back(S[i]);
            dfs(i+1,max,v,S);
            v.pop_back();
        }
        return;
    }
    vector<vector<int> > subsets(vector<int> &S) {
        
        sort(S.begin(),S.end());
        vector<int> v;
        dfs(0,S[S.size()-1],v,S);
        return ret;
    }
};