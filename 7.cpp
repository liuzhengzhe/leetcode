#include <iostream>
using namespace std;
#include <math.h>
#include <string.h>
class Solution {
public:
    int reverse(int x) {
        string stand="2147483647";
        string s;
        int start=1;
        int minus=0;
        int y=0;
        if(x==0){
            return 0;
        }
        if(x<0){
            minus=1;
            x=-x;
        }
        int tmp=0;
        while(1){
            y=x%10;
            x=x/10;
            if(start==1 and y==0){
                continue;
            }
            else if(start==1 and y!=0){
                start=0;
            }
            s+=y;
            tmp+=1;
            if(x==0){
                break;
            }

        }
        if(tmp==10){
            for(int i=0;i<10;i++){
                if(int(s[i])>int(stand[i]-'0')){
                    return 0;
                }
            }
        }
        int ret=0;
        for(int i=0;i<s.length();i++){
            ret+=int(s[s.length()-i-1])*((pow(10,i)));
        }
        if(minus==1){
            return -ret;
        }
        else{
            return ret;
        }



    }
};
int main(){
	Solution s;
	cout<<s.reverse(10900);
}