#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int> > ret;
    void dfs(int cur,vector<int> now,vector<int>& nums){
        ret.push_back(now);
        if(cur==nums.size()){
            return;
        }
        
        for(int i=cur;i<nums.size();i++){
            if(i>0){
                if(nums[i]!=nums[i-1] or i==cur){
                    now.push_back(nums[i]);
                    dfs(i+1,now,nums);
                    now.pop_back();
                }
            }
            else{
                now.push_back(nums[cur]);
                dfs(cur+1,now,nums);
                now.pop_back();                
            }

        }
        
    }
    
    
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> now;
        dfs(0,now,nums);
        return ret;
    }
};
int main()
{
    Solution s;
    int  v1[2] = {1,2};
    vector<int> nums(&v1[0],&v1[2]);
    s.subsetsWithDup(nums);
    return 0;
}