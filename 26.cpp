class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int len=1;
        if(!n){
            return NULL;
        }
        if(n==1){
            return 1;
        }
        for(int i=1;i<n;i++){
            if(A[i]!=A[i-1]){
                
                A[len]=A[i];
                len++;
            }
        }
        return len;
        
    }
};