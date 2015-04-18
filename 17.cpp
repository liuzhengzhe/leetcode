#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> ret;
    string convert(char c){
        switch(c){
            case '0':
                return " ";
            case '1':
                return "";
            case '2':
                return "abc";
            case '3':
                return "def";
            case '4':
                return "ghi";
            case '5':
                return "jkl";
            case '6':
                return "mno";
            case '7':
                return "pqrs";
            case '8':
                return "tuv";
            case '9':
                return "wxyz";
        }
    }
    void dfs(string d,string have){
        if(d.length()==0){
            ret.push_back(have);
            return;
        }
        string s=convert(d[0]);
        for(int i=0;i<s.length();i++){
            dfs(d.substr(1,d.length()-1),have+s[i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return ret;
        }
        dfs(digits,"");
        return ret;
    }
};
int main(){
    Solution s;
    s.letterCombinations("2");
    return 0;
}