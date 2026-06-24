/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxi=0;
        for(int i=0;i<intervals.size();i++){
           maxi=max(maxi,intervals[i].end);
        }
        vector<int>ans(maxi+5,0);
        for(int i=0;i<intervals.size();i++){
            ans[intervals[i].start]+=1;
            ans[intervals[i].end]-=1;
        }
        int count=ans[0];
        for(int i=1;i<ans.size();i++){
            ans[i]+=ans[i-1];
            count=max(count,ans[i]);
        }
        return count;
        
    }
};
