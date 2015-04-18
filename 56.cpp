#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
 /**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    static bool comp(Interval a,Interval b){
        return a.start<b.start;
    }
    vector<Interval> merge(vector<Interval> &intervals) {
        
        vector<Interval> ret;
        if(intervals.size()==0){
            return ret;
        }
        sort(intervals.begin(),intervals.end(),comp);
        int left=intervals[0].start;
        int right=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            //left=intervals[i].start;
            if(intervals[i].start<=right){
                right=max(right,intervals[i].end);
            }
            else{
                Interval itv=Interval(left,right);
                ret.push_back(itv);
                left=intervals[i].start;
                right=max(right,intervals[i].end);
            }
        }
        Interval itv=Interval(left,right);
        ret.push_back(itv);
        return ret;
        
    }
};
int main(){
    Solution s;
    vector<Interval> a;
    a.push_back(Interval(1,10));
    a.push_back(Interval(2,3));
    a.push_back(Interval(4,5));
    a.push_back(Interval(6,7));
    a.push_back(Interval(8,9));
    s.merge(a);
    return 0;
}