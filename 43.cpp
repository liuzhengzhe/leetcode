 #include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret;
        int r2=0;
        int g1=0;
        int g2=0;
        int g3=0;
        int g4=0;
        for(int i=0;i<num1.length()+num2.length()-1;i++){
            int m=0;
            for(int j=0;j<=i;j++){
                if(j<num1.length() and i-j<num2.length()){
                    int d1=num1[j]-'0';
                    int d2=num2[i-j]-'0';
                    m+=d1*d2;
                }
            }
            m+=g2;
            m+=10*g3;
            m+=100*g4;
            g1=m%10;
            g2=(m/10)%10;
            g3=(m/100)%10;
            g4=(m/1000)%10;
            ret=char(g1+'0')+ret;
        }
        while(g2!=0 or g3!=0){
            int m=g2+10*g3+100*g4;
            g1=m%10;
            g2=(m/10)%10;
            g3=(m/100)%10;
            g4=(m/1000)%10;
            ret=char(g1+'0')+ret;
        }
        while(ret[0]=='0'){
            ret=ret.substr(1,ret.length()-1);
        }
        if(ret==""){
            ret="0";
        }
        return ret;
    }
};
int main(){
    Solution s;
    s.multiply("9133","0");
    return 0;
}