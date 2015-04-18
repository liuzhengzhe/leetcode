#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[j][n-1-i]);
                swap(matrix[i][j],matrix[n-1-i][n-1-j]);
                swap(matrix[i][j],matrix[i][n-1-j]);
            }
        }
    }
};
int main(){
    Solution s;
    vector<int> a;
    vector<int> b;
    a.push_back(1);
    a.push_back(2);
    b.push_back(3);
    b.push_back(4);
    vector<vector<int> > c;
    c.push_back(a);
    c.push_back(b);
    s.rotate(c);
    return 0;
}