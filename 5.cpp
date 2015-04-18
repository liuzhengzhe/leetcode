#include <iostream>
using namespace std;
#include <string>
class Solution {
public:
    string longestPalindrome(string s) {
        int start=0;
        int maxi=0;
        for(int i=0;i<s.length();i++){
            int offset=0;
            int tmp=-1;
            while(s[i-offset]==s[i+offset]){
                offset++;
                tmp+=2; 
                if(i-offset<0 or i+offset>s.length()){
                    break;
                }
            }
            if(maxi<tmp){
                maxi=tmp;
                start=i-offset+1;                
            }

            
        }
        if(s.length()>1){
            for(int i=0;i<s.length()-1;i++){
                int offset=0;
                int tmp=0;
                if(s[i]==s[i+1]){
                    while(s[i-offset]==s[i+offset+1]){
                        offset++;
                        tmp+=2; 
                        if(i-offset<0 or i+offset>s.length()-1){
                            break;
                        }
                    }
                    if(maxi<tmp){
                        maxi=tmp;
                        start=i-offset+1;
                    }
                }
                
            }   
        }
        
        return s.substr(start,maxi);
    }
};
int main(){
    Solution s;
    string c="a";
    string ret=s.longestPalindrome(c);
    cout<<ret;
}