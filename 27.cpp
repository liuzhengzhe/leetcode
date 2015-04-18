class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len=0;
        int cu=0;
        for(int i=0;i<n;i++){
            if(A[i]!=elem){
                A[cu]=A[i];
                cu++;
                len++;
            }
        }
        return len;
    }
};