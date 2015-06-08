#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool valid(char c){
        if(c>'0' and c<='9'){
            return 1;
        }
        else{
            return 0;
        }
    }
    bool valid2(char c,char d){
        if(c=='1' or (c=='2' and d<'7' and d>='0')){
            return 1;
        }
        else{
            return 0;
        }
    }
    int numDecodings(string s) {
        int* d=new int[s.length()];
        if(valid(s[0])){
            d[0]=1;
        }
        else{
            return 0;
        }
        if(s.length()>1){
        if(valid(s[1])){
            if(valid2(s[0],s[1])){
                d[1]=2;
            }
            else{
                d[1]=1;
            }
        }
        else{
            if(s[0]=='1' or s[0]=='2')
                d[1]=1;
            else
                return 0;
        }
        }
            
        for(int i=2;i<s.length();i++){
            if(valid(s[i])){
                if(valid2(s[i-1],s[i])){
                    d[i]=d[i-2]+d[i-1];
                }
                else{
                    d[i]=d[i-1];
                }
            }
            else{
                if(s[i-1]=='1' or s[i-1]=='2')
                    d[i]=d[i-2];
                else
                    return 0;                    
            }

            
        }
        return d[s.length()-1];
        
    }
};
int main()
{
    Solution s;
    s.numDecodings("110");
    return 0;
}