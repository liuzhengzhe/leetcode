/*I = 1;
V = 5;
X = 10;
L = 50;
C = 100;
D = 500;
M = 1000;*/
class Solution {
public:
    int trans(char a){
        switch(a){
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
    }
    int romanToInt(string s) {
        int ret=trans(s[0]);
        for(int i=1;i<s.length();i++){
            if(trans(s[i])>trans(s[i-1])){
                ret-=2*trans(s[i-1]);
                ret+=trans(s[i]);
            }
            else{
                ret+=trans(s[i]);
            }
        }
        return ret;
        
    }
};
