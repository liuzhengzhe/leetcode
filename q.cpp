#include <iostream>
using namespace std;
#include <cstring>
class Solution {
public:
    string convert(string s, int numRows) {
       //calculate number
       if(numRows==1||numRows>=s.length())
       return s;
       int *a = new int[numRows];
       int slen = s.length();
       int period = 2*numRows-2;
       int intergral = slen/period;
       
       for(int i=0;i<numRows;++i)
       {
          if(i==0||i==numRows-1) a[i] =period;
          else a[i] = period*2;
          
       }
       if(slen%period>=numRows)
        {
            for(int i=0;i<numRows;++i)
            a[i]+=1;
            for(int j=0;j<slen%period-numRows;++j)
            {
                a[numRows-j-2]+=1;
            }
        }
        else {
            for(int i=0; i<slen%period; ++i)
             a[i]+=1;
        }
        
      string result;
      result.resize(slen+1,'\0');
      int *start = new int[numRows];
      start[0] = 0;
      for (int i=1;i<numRows;++i)
      {
          start[i]= a[i-1];
      }
      for(int i=0;i<intergral;++i)
      {
          //forward
          for(int j=0;j<numRows;++j)
          {
              result[i*period+j]=s[start[j]];
              start[j] +=1;
          }
          //backward;
          for(int j=0;j<numRows-2;++j)
          {
              result[i*period+numRows+j] = s[start[numRows-j-2]];
              start[numRows-j-2]+=1;
          }
      }
      
    
      if(slen%period>=numRows)
      {
          for(int i=0;i<numRows;++i)
          {
              result[intergral*period+i] = s[start[i]];
              start[i]+=1;
          }
          for(int j=0;j<slen%period-numRows;++j)
          {
              result[intergral*period+numRows+j] = s[start[numRows-j-2]];
              start[numRows-j-2]+=1;
          }
      }
      else 
      {
          for(int i=0;i<slen%period;++i)
          {
              result[intergral*period+i] = s[start[i]];
              start[i]+=1;
          }
      }
      return result;
        
    }
};
int main(){
    Solution s;
    cout<<s.convert("twckwuyvbihajbmhmodminftgpdcbquupwflqfiunpuwtigfwjtgzzcfofjpydjnzqysvgmiyifrrlwpwpyvqadefmvfshsrxsltbxbziiqbvosufqpwsucyjyfbhauesgzvfdwnloojejdkzugsrksakzbrzxwudxpjaoyocpxhycrxwzrpllpwlsnkqlevjwejkfxmuwvsyopxpjmbuexfwksoywkhsqqevqtpoohpd", 4);
    return 0;
}