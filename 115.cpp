class Solution {
public:
    int numDistinct(string s, string t) {
        int** d=new int* [s.length()+1];
        for(int i=0;i<s.length()+1;i++){
            d[i]=new int[t.length()+1];
        }
        for(int i=0;i<s.length()+1;i++){
            d[i][0]=1;
        }
    
        for(int i=1;i<t.length()+1;i++){
            d[0][i]=0;
        }       
        for(int i=1;i<s.length()+1;i++){
            for(int j=1;j<t.length()+1;j++){
                d[i][j]=d[i-1][j];
                if(s[i-1]==t[j-1]) d[i][j]+=d[i-1][j-1];
                
            }
        }
        return d[s.length()][t.length()];
        
    }
};
