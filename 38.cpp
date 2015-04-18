class Solution {
public:
    string read(string s){
        string r;
        if(s.length()==1){
            return '1'+s;
        }
        else{
            
            int tmp=1;
            for(int i=1;i<s.length();i++){
                if(s[i]!=s[i-1]){
                    r+=(tmp+'0');
                    tmp=1;
                    r+=s[i-1];
                }
                else{
                    tmp++;
                }
            }
            r+=(tmp+'0');
            r+=s[s.length()-1];            
        }
        return r;
    }
    string countAndSay(int n) {
        string one="1";
        for(int i=0;i<n-1;i++){
            one=read(one);
        }
        return one;

    }
};