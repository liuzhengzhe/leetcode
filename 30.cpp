 #include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        unordered_map<string,int> map;
        int len=L[0].length();
        vector<int> ret;
        for(int i=0;i<L.size();i++){
            if(map.find(L[i])==map.end()){
                map[L[i]]=1;
            }
            else{
                map[L[i]]++;
            }
        }
        if(S.length()<len*L.size()){
            return ret;
        }
        for(int i=0;i<=S.length()-len*L.size();i++){
            int offset=0;
            unordered_map<string,int> tmp=map;
            while(tmp.find(S.substr(i+offset,len))!=tmp.end()){
               
                if(tmp[S.substr(i+offset,len)]==1){
                    tmp.erase(S.substr(i+offset,len));
                }
                else{
                    tmp[S.substr(i+offset,len)]--;
                }
                offset+=len;
            }
            if(tmp.empty()==1){
                ret.push_back(i);
            }
        }
        return ret;
        
    }
};
int main(){
    Solution s;
    vector<string> vct;
    vct.push_back("foo");
    vct.push_back("bar");
    s.findSubstring("barfoothefoobarman",vct);
    return 0;
}