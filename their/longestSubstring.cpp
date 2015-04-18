#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int hash[256];
        for(int i=0; i<256; i++) hash[i] = -1;
        int start = 0, ans = 0;
        int i;
        for(i=0; i<s.size(); i++){
            if( -1 != hash[ s[i] ] ){
                if(ans < i-start) ans = i-start;
                for(int j=start; j<hash[ s[i] ]; j++) hash[j] = -1;
                if(hash[  s[i] ] + 1  > start )
                    start = hash[ s[i] ] +1;
            }
            hash[ s[i]] = i;
        }
        if(ans < i-start) ans = i-start;
        return ans;
    }
};
 
int main() {
    string str = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
    str = "abcdbef";
    Solution s ;
    cout << s.lengthOfLongestSubstring(str) << endl;
    return 0;
}