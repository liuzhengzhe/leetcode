class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret(pow(2,n),0);
        int max=pow(2,n);
        ret[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=pow(2,i-1);j<pow(2,i);j++){
                ret[j]=ret[pow(2,i)-j-1]+pow(2,i-1);
            }
        }
        return ret;
    }
};