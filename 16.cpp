class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        int ret=num[0]+num[1]+num[2];
        int tmp=0;
        sort(num.begin(),num.end());
        for(int i=0;i<num.size();i++){
            int start=i+1;
            int end=num.size()-1;
            while(start<end){
                tmp=num[i]+num[start]+num[end];
                if(abs(tmp-target)<abs(ret-target)){
                    ret=tmp;
                }
                if(tmp<target){
                    start++;
                }
                else if(tmp>target){
                    end--;
                }
                else{
                    return target;
                }
            }
            
        }
        return ret;
    }
};