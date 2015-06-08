class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int l=digits.size();
        vector<int> ret;
        int j=0;
        int have=0;
        for(int i=l-1;i>=0;i--){
            if(digits[i]==9){
                if(have==0){
                    ret.insert(ret.begin(),0);
                    j=1;
                }
                else{
                    ret.insert(ret.begin(),digits[i]);
                }
            }
            else{
                if(have==0){
                    ret.insert(ret.begin(),digits[i]+1);
                    have=1;
                }
                else{
                    ret.insert(ret.begin(),digits[i]);
                }
                j=0;
            }
        }
        if(j==1){
            ret.insert(ret.begin(),1);
        }
        return ret;
    }
};