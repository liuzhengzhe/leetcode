#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
#include <stack>
class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        int col1=0;
        int row1=0;
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                row1=1;
                break;
            }
        }        
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                col1=1;
                break;
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<col;j++){
                    matrix[i][j]=0;
                }
            }
        }      
        for(int j=1;j<col;j++){
            if(matrix[0][j]==0){
                for(int i=1;i<row;i++){
                    matrix[i][j]=0;
                }
            }
        }
        if(row1==1){
            for(int i=0;i<row;i++){
                matrix[i][0]=0;
            }
        }
        if(col1==1){
            for(int j=0;j<col;j++){
                matrix[0][j]=0;
            }
        }
        
    }
};

int main(){
    Solution s;
    vector<vector<int> > a;
    int q[4]={0,0,0,5};
    int w[4]={4,3,1,4};
    int y[4]={0,1,1,4};
    int r[4]={1,2,1,3};
    int t[4]={0,0,1,1};
    vector<int> b(&q[0],&q[4]);
    vector<int> c(&w[0],&w[4]);
    vector<int> d(&y[0],&y[4]);
    vector<int> e(&r[0],&r[4]);
    vector<int> f(&t[0],&t[4]);
    a.push_back(b);
    a.push_back(c);
    a.push_back(d);
    a.push_back(e);
    a.push_back(f);
    s.setZeroes(a);
    return 0;
}
