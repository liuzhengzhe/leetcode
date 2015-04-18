class Solution {
public:
    int maxArea(vector<int> &height) {
        int i=0;
        int j=height.size();
        int maxi=0;
        int tmp=0;
        while(i!=j){
            tmp=(j-i)*min(height[i],height[j]);
            maxi=max(maxi,tmp);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxi;
    }
};
