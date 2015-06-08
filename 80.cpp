class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int ret=0;
        unordered_map<int,int> m;
        if(n==0){
            return ret;
        }
        for(int i=0;i<n;){
            if(m.find(A[i])!=m.end() and m[A[i]]>=2){
                swap(A[i],A[n-1]);
                n--;
                continue;
            }
            else{
                ret++;
                if(m.find(A[i])!=m.end()){
                    m[A[i]]++;
                }
                else{
                    m[A[i]]=1;
                }
                i++;
            }
        }
        sort(A,A+n);
        return ret;
    }
};