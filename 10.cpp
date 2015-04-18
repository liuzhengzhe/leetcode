#include <iostream>
using namespace std;
#include <string.h>
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(strlen(s)==0){
            if(strlen(p)==0){
                return 1;
            }
            if(strlen(p)%2==0)
            {
                int x=1;
                while(p[x]=='*'){
                    x+=2;
                    if(x==strlen(p) or x>strlen(p)){
                        break;
                    }
                }
                if(x==strlen(p) or x>strlen(p)){
                    return 1;
                }
                else{
                    return 0;
                }
            }
            else{
                return 0;
            }
        }
        
        else if(strlen(p)==0){
            return 0;
        }
        
        int** res=new int*[strlen(s)];
        for(int i=0;i<strlen(s);i++){
            res[i]=new int[strlen(p)];
        }
        for(int i=0;i<strlen(s);i++){
            for(int j=0;j<strlen(p);j++){
                res[i][j]=0;
            }
        }

        if(s[0]==p[0] or p[0]=='.'){
            res[0][0]=1;
        }
        else{
            res[0][0]=0;
        }
        if(p[0]=='.' and p[1]=='*'){
            res[0][1]=1;
        }
        if(p[1]=='.' and p[2]=='*' and p[0]==s[0]){
            res[0][1]=1;
            res[0][2]==2;
        }
        if(p[1]=='*'){
            res[0][1]=1;
        }
        for(int j=1;j<strlen(p);j++){
            int i=0;
            if(p[j]!='*'){
                if((p[j]=='.' or p[j]==s[0]) and p[j-1]=='*'){
                    int y=1;
                    for(y=1;y<j;y+=2){
                        if(p[y]!='*'){
                            res[0][j]=0;
                            break;
                        }
                    }
                    if(y==j or y>j){
                    res[0][j]=1;}

                }
                else{
                                    res[0][j]=0;     
                                }
            }
            if(p[j]=='*' and p[j-1]!='.'){
                if(res[0][j-1]==1){
                    res[0][j]=1;
                }
                else if(j>1){
                    if(res[i][j-2]==1){
                        res[i][j]=1;
                    }
                }
                else if(j==1 and p[j-1]==s[0]){
                    res[i][j]=1;   
                }
                else{
                    res[i][j]=0;
                }
            }
            else if(p[j]=='*' and p[j-1]=='.'){
                if(res[i][j-1]==1){
                    res[i][j]=1;
                }
                else if(j>1){
                    if(res[i][j-2]==1){
                        res[i][j]=1;
                    }
                }
                else if(j==1){
                    res[i][j]=1;   
                }
                else{
                    res[i][j]=0;
                }
                
            }


        }
        











        for(int j=1;j<strlen(p);j++){
            for (int i=1;i<strlen(s);i++){
                if(p[j]!='*'){
                    if(p[j]==s[i] and res[i-1][j-1]==1){
                        res[i][j]=res[i-1][j-1];
                    }
                    else if(p[j]=='.' and res[i-1][j-1]==1){
                        res[i][j]=res[i-1][j-1];
                    }
                    else{
                        res[i][j]=0;
                    }
                }
                else if(p[j]=='*' and p[j-1]!='.'){
                    if(res[i][j-1]==1){
                        res[i][j]=1;
                    }
                    else if(j>1 and res[i][j-2]==1){
                            res[i][j]=1;
                        //if(res[i-1][j-2])
                    }
                    else if(p[j-1]==s[i] and s[i]==s[i-1] and res[i-1][j]==1){
                        res[i][j]=1;
                    }
                     else if(j==1 and i==1 and p[j-1]==s[i] and s[i]==s[0]){
                        res[i][j]=1;
                    }                   
                    else{
                        res[i][j]=0;
                    }
                }
                else if(p[j]=='*' and p[j-1]=='.'){
                    if(res[i][j-1]==1){
                        res[i][j]=1;
                    }
                    else if(j>1){
                        if(res[i][j-2]==1){
                            res[i][j]=1;
                        }
                        else if(res[i-1][j-2]==1){
                            res[i][j]=1;
                        }
                        else if(res[i-1][j]==1){
                             res[i][j]=1;                           
                        }
                    }
                    else if(j==1){
                        res[i][j]=1;   
                    }
                    else{
                        res[i][j]=0;
                    }
                    
                }
            }
        }
        return res[strlen(s)-1][strlen(p)-1];
    }
};
int main(){
    Solution s;
    char* a=new char[19];
    char* b=new char[15];
    a="aaabaaaababcbccbaab";
    b="c*c*.*c*a*..*c*";
    cout<<s.isMatch(a,b);
    return 0;
}