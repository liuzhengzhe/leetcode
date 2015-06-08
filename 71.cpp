#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <stack>
class Solution {
public:
    void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
    {
      std::string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(std::string::npos != pos2)
      {
        v.push_back(s.substr(pos1, pos2-pos1));
     
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(s.substr(pos1));
    }
    string simplifyPath(string path) {
        stack<string> s;
        string ret="";
        vector<string> paths;
        SplitString(path,paths,"/");
        for(int i=0;i<paths.size();i++){
            if(paths[i]==""){
                continue;
            }
            else if(paths[i]==".."){
                if(s.empty()==0){
                    s.pop();
                }
                else{
                    continue;
                }
            }
            else if(paths[i]=="."){
                continue;
            }
            else{
                s.push(paths[i]);
            }
        }
        string r;
        
        while(s.empty()==0){
            
            r=s.top();
            s.pop();
            ret=r+ret;
            ret="/"+ret;
        }
        
        if(ret==""){
            ret="/";
        }
        return ret;
    }
};
int main(){
    Solution s;
    cout<<s.simplifyPath("/..");
    return 0;
}