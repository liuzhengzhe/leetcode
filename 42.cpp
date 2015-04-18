class Solution {
public:
    int trap(int A[], int n) {
        int left[n];
        int tmp=0;
        left[0]=0;
        for(int i=1;i<n;i++){
            
            if(A[i-1]>tmp){
                tmp=A[i-1];
                
            }
            left[i]=tmp;
            
        }
        int right[n];
        tmp=0;
        right[n-1]=0;
        for(int i=n-2;i>-1;i--){
            
            if(A[i+1]>tmp){
                tmp=A[i+1];
                
            }
            right[i]=tmp;
        }
        int ret=0;
        for(int i=0;i<n;i++){
            int b=min(left[i],right[i]);
            if(A[i]<b){
                ret+=(b-A[i]);
                
            }
            
        }        
        return ret;
        
    }
};