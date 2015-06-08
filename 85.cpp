#include <iostream>
using namespace std;
#include <vector>
#include <stack>
class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
        
        int r=matrix.size();
        
        if(r==0){
            return 0;
        }
        int c=matrix[0].size();
        vector<char> h(c,0);
        int maximum=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int x=i;
                h[j]=0;
                while(x>=0 and matrix[x][j]=='1'){
                    x--;
                    h[j]++;
                }
                
            }
            maximum=max(maximum,findmax(h));
        }
        return maximum;
        
    }
    int l;
    int findmax(vector<char> &h){
        stack<char> s;
        int m=0;
        for(int i=0;i<h.size();i++){
            while(s.empty()==0 and h[s.top()]>h[i]){
                int b=h[s.top()];
                s.pop();
                if(s.empty()==0){
                    l=i-1-s.top();
                }
                else{
                    l=i-1;
                }
                m=max(m,l*b);
                
            }
            s.push(i);
        }
        while(s.empty()==0){
            int b=h[s.top()];
            s.pop();
            if(s.empty()==0){
                l=h.size()-1-s.top();
            }
            else{
                l=h.size()-1;
            }
            m=max(m,l*b);           
        }
        return m;
    }
    
};
int main(){
    Solution s;
    vector<vector<char> > a;
    vector<char> b;
    b.push_back('1');
    a.push_back(b);
    s.maximalRectangle(a);
    return 0;
}