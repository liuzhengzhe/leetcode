#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <stack>
class Solution {
public:
    int minDistance(string word1, string word2) {
        int** d=new int*[word1.length()+1];
        for(int i=0;i<word1.length()+1;i++){
            d[i]=new int[word2.length()+1];
        }
        for(int i=0;i<word1.length()+1;i++){
            d[i][0]=i;
        }
        for(int i=0;i<word2.length()+1;i++){
            d[0][i]=i;
        }        
        int min1=0;
        int min2=0;
        for(int i=1;i<=word1.length();i++){
            for(int j=1;j<=word2.length();j++){
                min1=min(d[i-1][j],d[i][j-1])+1;
                if(word1[i-1]==word2[j-1]){
                    min2=d[i-1][j-1];
                }
                else{
                    min2=d[i-1][j-1]+1;
                }
                d[i][j]=min(min1,min2);
                
            }
        }
        return d[word1.length()][word2.length()];
    }
};