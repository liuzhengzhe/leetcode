#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int mySqrt(int x) {
        long long low=0;
        long long high=x/2+1;
        while(1){
            long long mid=(low+high)/2;
            if(low>high){
                break;
            }
            
            long long res=mid*mid;
            if(res<x){

                low=mid+1;
            }
            else if(res>x){

                high=mid-1;
            }
            else{
                return mid;
            }
        }
        return high;
    }
};
int main(){
    Solution s;
    cout<<s.mySqrt(5);
    return 0;
}