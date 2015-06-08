#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
class Solution {
public:
    string minWindow(string s, string t) {
        string ret;
        unordered_map<char,int> h,h1,h2;
        for(int i=0;i<t.length();i++){
            if(h.find(t[i])!=h.end()){
                h[t[i]]++;
            }
            else{
                h[t[i]]=1;
            }
        }
        h1=h;
        h2=h;
        int right=0;
        int start=1;
        for(int i=0;i<s.length();i++){
            if(i==9){
                int x=0;
            }
            right=max(i,right);

            int n=1;
            for(;right<s.length();){
                if(n==0 or start==1){
                    h2[s[right]]--;
                    if(h.find(s[right])!=h.end()){
                        h[s[right]]--;
                        
                    }
                    if(h[s[right]]==0){
                        h.erase(s[right]);
                    }

                }
                 if(h.empty()){
                    if(right-i<ret.length() or ret.length()==0){
                        ret=s.substr(i,right-i+1);
                    }
                    break;
                }

                right++; 
                if(right==s.length()){
                    right=s.length()-1;
                    break;
                }
                n=0;     
                start=0;        
            }
            if(i==1){
                int x=0;
            }
            if(h1.find(s[i])!=h1.end()){
                if((h2.find(s[i])!=h2.end() and h2[s[i]]>=0) or h2.find(s[i])==h2.end()){

                    if(h.find(s[i])!=h.end()) {
                        h[s[i]]++;
                    }
                    else{
                        h[s[i]]=1;
                    }
                }
                if(h2.find(s[i])!=h2.end()) {

                    h2[s[i]]++;
                }
                else{
                    h2[s[i]]=1;
                }


            }
        }
        return ret;
    }
};
int main(){
    Solution s;
    cout<<s.minWindow("bba", "ab");
    return 0;
}