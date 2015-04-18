#include <iostream>
using namespace std;
class Solution {
public:
    string convert(int i,char a,char b,char c){
        string ret="";
        switch(i){
            case 9:
                ret+=c;
                ret+=a;
                break;
            case 8:
                ret+=b;
                ret+=c;
                ret+=c;
                ret+=c;
                break;
            case 7:
                ret+=b;
                ret+=c;
                ret+=c;
                break;
            case 6:
                ret+=b;
                ret+=c;
                break;
            case 5:
                ret+=b;
                break;
            case 4:
                ret+=c;
                ret+=b;
                break;
            case 3:
                ret+=c;
                ret+=c;
                ret+=c;
                break;
            case 2:
                ret+=c;
                ret+=c;
                break;
            case 1:
                ret+=c;
                break;
        }
        return ret;
        
        
    }
    string intToRoman(int num) {
        char* n=new char[4];
        for(int i=0;i<4;i++){
            n[i]='0';
        }
        int ind=0;
        while(num>0){
            n[4-1-ind]=num%10+'0';
            num=num/10;
            ind++;
            
        }
        string a=convert(n[3]-'0','X','V','I');
        string b=convert(n[2]-'0','D','L','X');
        string c=convert(n[1]-'0','M','C','D');
        string d=convert(n[0]-'0',' ',' ','M');
        return d+c+b+a;
    }
};
int main(){
    Solution s;
    cout<<s.intToRoman(10);
    return 0;
}