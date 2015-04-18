#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        int a=0;
        vector<vector<int> > ret;
        
        if(n==0){
            return ret;
        }
        for(int i=0;i<n;i++){
            vector<int> tmp;
            ret.push_back(tmp);
            for(int j=0;j<n;j++){
                ret[i].push_back(0);
            }
        }
        int left=0;
        int right=n-1;
        int up=0;
        int down=n-1;
        int dir=1;
        int i=0;
        int j=0;
        while(a<n*n){
            a++;
            ret[i][j]=a;   
            if(dir==1){
                if(j==right){
                    up++;
                    i++;
                    dir=2;
                }
                else{
                    j++;
                }
            }
            else if(dir==2){
                if(i==down){
                    right--;
                    dir=3;
                    j--;
                }
                else{
                    i++;
                }                
            }
            else if(dir==3){
                if(j==left){
                    down--;
                    dir=4;
                    i--;
                }
                else{
                    j--;
                }                
            }
            else if(dir==4){
                if(i==up){
                    left++;
                    dir=1;
                    j++;
                }
                else{
                    i--;
                }
            }
            
        }
        return ret;
    }
};
int main(){
    Solution s;
    s.generateMatrix(1);
    return 0;
}