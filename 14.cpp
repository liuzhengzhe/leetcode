class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size()==0){
            return "";
        }
        int ret=0;
        int stop=0;
        while(1){
            char c=strs[0][ret];
            for(int i=0;i<strs.size();i++){
                if(strs[i].length()==ret){
                    stop=1;
                    break;
                }
                if(strs[i][ret]!=c){
                    stop=1;
                    break;
                }
            }
            if(stop==1){
                break;
            }
            ret++;
            
            
        }
        return strs[0].substr(0,ret);
    }
};
