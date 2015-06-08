class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> s;
        int m=0;
        int l;
        int c=0;
        for(int i=0;i<height.size();i++){
            while(s.empty()==0 and height[s.top()]>height[i]){
                l=height[s.top()];
                s.pop();
                if(s.empty()){
                    c=i;
                }
                else{
                    c=i-s.top()-1;
                }
                m=max(m,c*l);
                
            }
            s.push(i);
            
            
        }
        c=0;
        while(s.empty()==0){
            
            l=height[s.top()];
            s.pop();
            if(s.empty()){
                c=height.size();
            }
            else{
                c=height.size()-s.top()-1;
            }
            m=max(m,c*l);
        }
        return m;
        
    }
};8