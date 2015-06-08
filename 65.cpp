#include <iostream>
using namespace std;
#include <vector>
/*class Solution {
public:
    bool isNumber(string s) {
        int flag1=0;
        int flag2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                if(i==0 or i==s.length()-1){
                    return false;
                }
                if(flag1==1){
                    return false;
                }
                else{
                    flag1=1;
                }
            }
            if(s[i]=='e'){
                if(i==0 or i==s.length()-1){
                    return false;
                }
                if(flag2==1){
                    return false;
                }
                else{
                    flag2=1;
                }
            }
            if(s[i]<'0' and s[i]>'9' and s[i]!='.' and s[i]!='e'){
                return false;
            }
            
        }
        
        return 1;
    }
};*/
class Solution {
public:
    bool isNumber(string s) {
        int h=0;
        int r=s.length()-1;
        while(s[h]==' '){
            h++;
        }
        while(s[r]==' '){
            r--;
        }
        s=s.substr(h,r-h+1);
        if(s=="") return 0;
        int flag1=0;
        int flag2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='.'){
                if(s.length()==1){
                    return 0;
                }
                if(flag2==1) return 0;
                if(i!=0 and s.length()-1){
                    if((s[i-1]<'0' or s[i-1]>'9') and (s[i+1]<'0' or s[i+1]>'9')){
                        return 0;
                    }
                }
                if(flag1==1){
                    return false;
                }
                else{
                    flag1=1;
                }
            }
            if(s[i]=='e'){
                if(i==0 or i==s.length()-1){
                    return false;
                }
                if(s[i-1]=='+' or s[i-1]=='-'){
                    return 0;
                }
                if(s[i+1]=='.') return 0;
                if(i==1){
                    if(s[i-1]=='.') return 0;
                }
                if(flag2==1){
                    return false;
                }
                else{
                    flag2=1;
                }
            }
            if(s[i]==' '){
                return 0;
            }
            if(s[i]=='-' or s[i]=='+'){
                if(i>0){
                    if(s[i-1]!='e'){
                        return 0;
                    }
                }
                if(i==s.length()-1) return 0;
                if(i<s.length()-1){
                    if((s[i+1]<'0' or s[i+1]>'9') and s[i+1]!='.'){
                        return 0;
                    }
                }
                
            }
            if((s[i]<'0' or s[i]>'9') and s[i]!='.' and s[i]!='e' and s[i]!=' ' and s[i]!='-' and s[i]!='+'){
                return false;
            }
            
        }
        return 1;
    }
};
int main(){
    Solution s;
    cout<<s.isNumber("0.8");
    return 0;
}