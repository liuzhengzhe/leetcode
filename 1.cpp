#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int one;
        int two;
        unordered_map<int,int> map;
        for (int i=0;i<numbers.size();i++){
            map[numbers[i]]=i;
        }
         for (auto& x: map){
          std::cout << x.first << ": " << x.second << std::endl;
        }
        for (int i=0;i<numbers.size();i++){
            int reminder=target-numbers[i];
            if (map.find(reminder)!=map.end()){
                if(map[reminder]!=i){
                    one=i;
                    two=map[reminder];
                    break;
                }
                
            }
        }
        vector<int> ret(one,two+1);
        cout<<one<<two;
        return ret;        

    }
};
int main(){
   Solution sol;
   vector<int> a;
   a.push_back(0);
   a.push_back(4); 
   a.push_back(3);
   a.push_back(0);
   sol.twoSum(a,0);
}
