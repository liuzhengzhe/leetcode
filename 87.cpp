#include <iostream>
using namespace std;
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int l=s1.length();
        if(l!=s2.length()){
            return 0;
        }
        int d[l][l][l+1];
        for(int k=1;k<=l;k++){
            for(int i=0;i<=l-k;i++){
                for(int j=0;j<=l-k;j++){
                    d[i][j][k]=0;    
                }
            }
        }
        for(int i=0;i<l;i++){
            for(int j=0;j<l;j++){
                if(s1[i]==s2[j]){
                    d[i][j][1]=1;
                }
                else
                    d[i][j][1]=0;
            }
        }
        for(int k=2;k<=l;k++){
            for(int i=0;i<=l-k;i++){
                for(int j=0;j<=l-k;j++){
                    for(int x=1;x<k;x++){
                        d[i][j][k]=(d[i][j][x] && d[i+x][j+x][k-x] )||(d[i][j+k-x][x] && d[i+x][j][k-x])||d[i][j][k];

                    }
                    
                }
            }
        }
        return d[0][0][l];
        
    }
};
int main()
{
    Solution s;
    cout<<s.isScramble("abc", "cba");
    return 0;
}