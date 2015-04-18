class Solution {
public:
    int jump(int A[], int n) {
        int* d=new int[n];
        memset(d,99999,sizeof(d));
        for(int i=0;i<n;i++){
            for(int j=1;j<=A[i];j++){
                if(j+i<n){
                    if(d[j+i]>A[i]+1){
                        d[j+i]+=1;
                    }
                }
            }
        }
        return d[n-1];
    }
};