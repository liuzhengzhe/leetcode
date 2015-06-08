#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> ret;
    string t;
    bool valid(string s){
        if(s.length()==1){
            return 1;
        }
        if(s.length()==2){
            if(s[0]=='0'){
                return 0;
            }
            return 1;
        }
        if(s.length()==3){
            if(s[0]=='0') return 0;
            if(s[0]=='1') return 1;
            if(s[0]=='2'){
                if(s[1]<'5'){
                    return 1;
                }
                if(s[1]=='5'){
                    if(s[2]<'6'){
                        return 1;
                    }
                }
            }
        }
        return 0;
    }
    bool dfs(int p,int cur,int tmp[],string s){
        if(cur==4){
            if(valid(s.substr(p,s.length()-p))){
                t="";
                t+=s.substr(0,tmp[1]);
                t+='.';
                t+=s.substr(tmp[1],tmp[2]-tmp[1]);
                t+='.';
                t+=s.substr(tmp[2],tmp[3]-tmp[2]);
                t+='.';
                t+=s.substr(tmp[3],s.length()-tmp[3]);
                ret.push_back(t);
                return 1;
            }
            else
                return 0;
        }
        
        for(int i=p+1;i<s.length();i++){
            tmp[cur]=i;
            if(valid(s.substr(tmp[cur-1],tmp[cur]-tmp[cur-1]))){
                
                dfs(i,cur+1,tmp,s);
                
            }
            tmp[cur]=0;
        }
        return 0;
    }
    
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12){
            return ret;
        }
        int a[5]={0,0,0,0,0};
        dfs(0,1,a,s);
        return ret;
    }
};
int main()
{
    Solution s;
    s.restoreIpAddresses("0000");
    return 0;
}