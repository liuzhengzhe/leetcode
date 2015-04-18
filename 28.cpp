class Solution {
public:
    int strStr(char *haystack, char *needle) {
        if(strlen(haystack)<strlen(needle)){
            return -1;
        }
        for(int i=0;i<strlen(haystack)-strlen(needle)+1;i++){
            int j=0;
            for(j=0;j<strlen(needle);j++){
                if(haystack[i+j]!=needle[j]){
                    break;
                }
            }
            if(j==strlen(needle)){
                return i;
            }
        }
        return -1;
    }
};