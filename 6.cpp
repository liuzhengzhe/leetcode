#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int nRows) {
        int step=2*nRows-2;
        string ret="";
        int t=0;
        if(nRows==1){
            return s;
        }
        if(s.length()==0){
            return "";
        }
        for(int i=0;i<nRows;i++){
            if(i==0 or i==nRows-1){
                t=i;
                while(t<s.length()){
                    ret+=s[t];
                    t+=step;
                }
            }
            else{
                int t=i;
                int u=nRows*2-i-2;
                while(1){
                    if(t>s.length()-1){
                        break;
                    }
                    ret+=s[t];
                    t+=step;
                    if(u>s.length()-1){
                        break;
                    }
                    ret+=s[u];
                    u+=step;        
                }                
            }
        }
        return ret;
         
        
    }
};
int main(){
    Solution s;
    cout<<s.convert("PAYPALISHIRING",3);
}