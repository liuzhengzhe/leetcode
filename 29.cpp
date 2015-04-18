 #include <iostream>
using namespace std;
#include <math.h>
#include <stdlib.h>
class Solution {
public:
    int divide(int dividend, int divisor) {
        int minus=0;
        if(dividend<0 and divisor>0){
            minus=1;
        }
        if(dividend>0 and divisor<0){
            minus=1;
        }
        unsigned long dvd;
        unsigned long dvs;
        if(dividend==-2147483648){
            dvd=2147483648;
        }
        else{
            dvd = abs(dividend);
        }
        if(divisor==-2147483648){
            dvs=2147483648;
        }
        else{
            dvs = abs(divisor);
        }
        
        long long res=0;
        unsigned long d1=dvd;
        unsigned long d2=dvs;
        
        
        if(d1<d2){
            return 0;
        }
        if(d1==d2 and minus==0){
            return 1;
        }
        if(d1==d2 and minus==1){
            return -1;
        }        
        while(d1>=d2){
            long long cnt=1;
            
            while(d2+d2<=d1){
                d2<<=1;
                cnt<<=1;
            }
            d1-=d2;
            res+=cnt;
            d2=abs(dvd);
        }
        //if(res>MAX_INT) return MAX_INT;
        if(minus==0) return res>2147483647?2147483647:res;
        else return res<-2147483647?2147483647:-res;
    }
};

int main(){
    Solution s;
    s.divide(-2147483648, -1);
    return 0;
}
/*
class Solution {
public:
    int divide(int dividend, int divisor) {
        int minus=0;
        if(dividend<0 and divisor>0){
            minus=1;
        }
        if(dividend>0 and divisor<0){
            minus=1;
        }
        long res=0;
        int d1=abs(dividend);
        int d2=abs(divisor);
        int cnt=1;
        while(d1>d2){
            d2<<=1;
            cnt<<=1;
        }
        int ini=d2;
        int inicnt=cnt;
        while(d1>0){
            while(d1<d2){
                d2>>=1;
                cnt>>=1;
            }
            d1-=d2;
            //d2=divisor;
            res+=cnt;
        }
        //if(res>MAX_INT) return MAX_INT;
        if(minus==0) return res;
        else return -res;
    }*/
