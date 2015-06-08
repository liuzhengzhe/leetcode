#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int h=0;
        int r=nums.size()-1;
        int l=nums.size();
        while(1){
            if(h>r){
                break;
            }
            int mid=(h+r)/2;
            if(nums[mid]==target){
                return 1;
            }
            if(nums[mid]<nums[r]){
                if(target>nums[mid] and target<=nums[r]){
                    h=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            else if(nums[mid]>nums[r]){
                if(target<nums[mid] and target>=nums[0]){
                    r=mid-1;
                }
                else{
                    h=mid+1;
                }
            }
            else{
                r--;
            }
            
            
        }
        return 0;
    }
};
int main(){
    Solution s;
    vector<int> a;
    a.push_back(3);
    a.push_back(5);
    a.push_back(1);
    cout<<s.search(a, 3);
    return 0;
}