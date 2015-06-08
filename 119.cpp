class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int *a=new int[rowIndex+1];
        for(int i=0;i<rowIndex+1;i++) a[i]=0;
        a[0]=1;
        vector<int> ret(a,a+rowIndex+1);
        
        for(int i=0;i<=rowIndex;i++){
            for(int j=i;j>0;j--){
                ret[j]=ret[j]+ret[j-1];
            }
        }
        return ret;
    }
};
