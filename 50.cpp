#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    double rec(double x,long n){
        if(n==1){
            return x;
        }
        if(n==2){
            return x*x;
        }
        if(n%2==0){
            double y=rec(x,n/2);
            return y*y;
        }
        else{
            double y=rec(x,n/2);
            return y*y*x;
        }
        
    }
    double pow(double x, int n) {
        long m=n;
        if(m>0){
            return rec(x,m);
        }
        if(m==0){
            return 1;
        }
        if(m<0){
            return 1/rec(x,-m);
        }
    }
};
int main(){
    Solution s;
    s.pow(1.0,-2147483648);
    return 0;
}