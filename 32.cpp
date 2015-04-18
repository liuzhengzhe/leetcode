 #include <iostream>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        int ret=0;
        int *dp=new int[s.length()];
        
        dp[0]=0;
        for(int i=1;i<s.length();i++){
            if(s[i]=='('){
                dp[i]=0;
            }
            else{
                int j=i-dp[i-1]-1;
                if(j>=0){
                    if(s[j]=='('){
                        dp[i]=dp[j-1]+2+dp[i-1];
                    }
                    else{
                        dp[i]=0;
                    }
                }
                else{
                    dp[i]=0;
                }
            }

        }
        
        for(int i=0;i<s.length();i++){
            if(ret<dp[i]){
                ret=dp[i];
            }
        }
        return ret;
    }
};
/*class Solution {
public:
    int c(char a){
        if(a=='('){
            return -1;
        }
        else if(a==')'){
            return 1;
        }
    }
    int longestValidParentheses(string s) {
        
        int ret=0;
        int len=s.length();
        int **dp=new int*[len];
        for(int i=0;i<len;i++){
            dp[i]=new int[len];
        }
        for(int i=0;i<len;i++){
            dp[i][i]=c(s[i]);
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(dp[i][j-1]==1 and c(s[j])==-1){
                    for(int x=j;x<len;x++){
                        dp[i][len-1]=1;
                    }
                  
                  break;
                }
                else{
                    dp[i][j]=dp[i][j-1]+c(s[j]);
                }
            }
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
                if(dp[i][j]==0){
                    if(j-i>ret){
                        ret=j-i;
                    }
                }
                
            }
        }
        return ret;
        
    }
};*/
int main(){
    Solution s;
    s.longestValidParentheses(")()())()()(");
    return 0;
}