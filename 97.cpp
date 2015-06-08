class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return 0;
        int **d=new int*[s1.length()+1];
        for(int i=0;i<s1.length()+1;i++){
            d[i]=new int[s2.length()+1];
        }
        d[0][0]=1;
        int f=1;
        for(int i=0;i<s1.length();i++){
            if(f==1 and s1[i]==s3[i]){
                d[i+1][0]=1;
            }
            else{
                f=0;
                d[i+1][0]=0;
            }
        }
        f=1;
        for(int i=0;i<s2.length();i++){
            if(f==1 and s2[i]==s3[i]){
                d[0][i+1]=1;
            }
            else{
                f=0;
                d[0][i+1]=0;
            }
        }
        for(int i=1;i<s1.length()+1;i++){
            for(int j=1;j<s2.length()+1;j++){
                if((s1[i-1]==s3[i+j-1] and d[i-1][j]==1) or (s2[j-1]==s3[i+j-1] and d[i][j-1]==1)){
                    d[i][j]=1;
                }
                else{
                    d[i][j]=0;
                }
            }
        }
        return d[s1.length()][s2.length()];
        
        
    }
};
