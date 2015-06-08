class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int rows=triangle.size();
        int *a=new int[rows];
        for(int i=0;i<rows;i++) a[i]=0;
        vector<int> dis(a,a+triangle.size());
        if(rows==0) return 0;
        //dis[0]=triangle[0][0];
        for(int i=0;i<rows;i++){
            dis[i]=dis[i-1]+triangle[i][i];
            for(int j=i-1;j>0;j--){
                dis[j]=min(dis[j],dis[j-1])+triangle[i][j];
            }
            if(i!=0){
                dis[0]=dis[0]+triangle[i][0];
            }
        }
        int min=dis[0];
        for(int i=0;i<rows;i++)
        {
            if(dis[i]<min) min=dis[i];
        }
        return min;
        
    }
};
