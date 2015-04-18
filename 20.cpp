#include <stack>
#include <iostream>
using namespace std;
class Solution {
public:
    bool comp(char a,char b){
        switch (a){
            case '(':
                if(b==')'){
                    return 1;
                }
                else{
                    return 0;
                }
            case '[':
                if(b==']'){
                    return 1;
                }
                else{
                    return 0;
                }
            case '{':
                if(b=='}'){
                    return 1;
                }
                else{
                    return 0;
                }
            default:
                return 0;
        }
    }
    bool isValid(string s) {
        
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(st.empty()){
                st.push(s[i]);
            }
            else if(comp(st.top(),s[i])){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main(){
    Solution s;
    s.isValid("[");
    return 0;
}