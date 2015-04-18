#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        
        vector<vector<int> > ret;
        vector<vector<int> > ret2;
        sort(num.begin(),num.end());
        vector<int> n=num;
        if(n.size()==0){
            return ret;
        }
        /*for(int i=0;i<num.size()-1;i++){
            if(num[i]==num[i+1]){
                continue;
            }
            n.push_back(num[i]);
        }*/
        if(n.size()<3){
            return ret;
        }
        for(int i=0;i<n.size()-2;i++){
            int start=i+1;
            int end=n.size()-1;
            while(start<end){
                if(n[start]+n[end]+n[i]>0){
                    end--;
                }
                else if(n[start]+n[end]+n[i]<0){
                    start++;
                    
                }
                else{
                    vector<int> va;
                    va.push_back(n[i]);
                    va.push_back(n[start]);
                    va.push_back(n[end]);
                    ret.push_back(va);
                    //it++;
                    start++;
                    end--;
                    while(start<end and n[start]==n[start+1]){
                        start++;
                    }
                    while(start<end and n[end]==n[end-1]){
                        end--;
                    }
                }
            }
            while(i < num.size()-1&&num[i] == num[i+1])
                ++i;
        }

        return ret;
    }
};
int main(){
    Solution s;
    vector<int> v;
    v.push_back(-2);
    v.push_back(0);
    v.push_back(1);    
    v.push_back(1);
    v.push_back(2);
    s.threeSum(v);
    return 0;
}