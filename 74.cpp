#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int u=0;
        int d=matrix.size()-1;
        int l=0;
        int r=matrix[0].size()-1;
        int up=0;
        int mid=0;
        while(1){
            if(u>d){
                break;
            }
            mid=(u+d)/2;
            if(matrix[mid][0]==target or matrix[mid][r]==target){
                return 1;
            }
            else if(matrix[mid][0]>target){
                d=mid-1;
            }
            else if(matrix[mid][r]<target){
                u=mid+1;
            }
            else{
                break;
            }
        }
        //u+=up;
        while(1){
            if(l>r){
                break;
            }
            int m=(l+r)/2;
            if(matrix[mid][m]==target){
                return 1;
            }
            else if(matrix[mid][m]>target){
                r=m-1;
            }
            else{
                l=m+1;
            }                    

        }
        return 0;
    }
};
int main(){
    Solution s;
    vector<vector<int> > a;
    int q[4]={1};
    int w[4]={3};
    vector<int> b(&q[0],&q[1]);
    vector<int> c(&w[0],&w[1]);
    a.push_back(b);
    a.push_back(c);
    cout<<s.searchMatrix(a,3);
    return 0;
}