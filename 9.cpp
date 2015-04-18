#include <iostream>
using namespace std;
#include <math.h>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        if(x==0){
            return 1;
        }
        int s=1;
        int t=1;
        while(s*10<x){
            s*=10;
            if(s==pow(10,9)){
                break;
            }
        }
        if(x/10==0){
            return 1;
        }
        int head=x/s;
        int rear=x%10;
        while(1){
            if(head==rear){
                s/=10;
                t*=10;
                if(s==t or s==t*10 or s<t){
                    return 1;
                }
                head=(x/s)%10;
                rear=(x/t)%10;

                
            }
            
            else{
                return 0;
            }
        }
        return 1;
    }
};
int main(){
    Solution s;
    cout<<s.isPalindrome(11);
}