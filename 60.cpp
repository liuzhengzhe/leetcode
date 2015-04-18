#include <iostream>
using namespace std;
#include <string>
#include <cmath>
class Solution {
public:
    int multi(int n){
        int ret=1;
        for(int i=1;i<=n;i++){
            ret*=i;
        }
        return ret;
    }
    string helper(int k,string str,string src){
        int n=src.length();
        if(n==0){
            return str;
        }
        int dvd=multi(n-1);
        int now=(k-1)/dvd;
        str+=src[now];
        src.erase(now,1);
        k-=now*multi(n-1);
        
        return helper(k,str,src);
    }
    string getPermutation(int n, int k) {
        string src="";
        for(int i=1;i<=n;i++){
            src+=i+'0';
        }
        string ret="";
        return helper(k,ret,src);
    }
};
int main(){
    Solution s;
    cout<<s.getPermutation(4,9);
    return 0;
}