#include <iostream>
#include <math.h>
using namespace std;
class Solution {
public:
    int atoi(string str) {
        int start=1;
        int minus=0;
        string ret="";
        for(int i=0;i<str.length();i++){
            if(start==1){
                if(str[i]=='+'){
                    start=0;
                }
                else if(str[i]=='-'){
                    start=0;
                    minus=1;
                }
                else if(str[i]-'0'<1 or str[i]-'0'>9){
                    continue;
                }
                else{
                    start=0;
                    ret+=str[i];
                }
            }
            else{
                if(str[i]-'0'<0 or str[i]-'0'>9){
                    break;
                }
                else{
                    ret+=str[i];
                }
            }
            
        }
        if(ret.length()==0){
            return 0;
        }
        long final=0;
        for(int i=0;i<ret.length();i++){
            final+=(ret[i]-'0')*pow(10,ret.length()-1-i);
        }
        if(final>2147483647 or final<-2147483648){
            return 0;
        }
        else{
            if(minus==1){
                return int(-final);
            }
            return int(final);
        }
        
    }
};
int main(){
    Solution s;
    cout<<s.atoi("-2147483648");
    return 0;
}