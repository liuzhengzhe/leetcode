class Solution {
public:
    string addBinary(string a, string b) {
        int l1=a.length();
        int l2=b.length();
        string ret;
        int j=0;
        while(l1<l2){
            a='0'+a;
            l1++;
        }
        while(l1>l2){
            b='0'+b;
            l2++;
        }
        for(int i=1;i<=l2;i++){
            int value=a[l1-i]+b[l2-i]+j-'0'-'0';
            if(value>=2){
                ret=char('0'+value-2)+ret;
                j=1;
            }
            else{
                ret=char(value+'0')+ret;
                j=0;
            }
        }
        if(j==1){
            ret='1'+ret;
        }
        return ret;
    }
};