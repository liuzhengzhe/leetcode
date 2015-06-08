class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i;
        int j;
        int k;
        for(i=m-1,j=n-1,k=m+n-1;k>=0;k=i+j+1){
            if(i>=0 and j>=0){
                
                if(nums1[i]>nums2[j]){
                    nums1[k]=nums1[i];
                    i--;
                }
                else{
                    nums1[k]=nums2[j];
                    j--;
                }
            }
            else if(i<0){
                nums1[k]=nums2[j];
                j--;
            }
            else{
                break;
            }
            
        }
        
    }
};