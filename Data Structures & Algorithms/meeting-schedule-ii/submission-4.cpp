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
    static bool comp(Interval a,Interval b){
        return a.start<b.start;
    }
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),comp);
        vector<int>last;
        int n=intervals.size();
        int ans=0;
        if(n==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            if(last.empty()){
                ans++;
                last.push_back(intervals[i].end);
            }
            else{
                int f=1;
                for(int j=last.size()-1;j>=0;j--){
                    if(intervals[i].start>=last[j]){
                        f=0;
                        last[j]=max(last[j],intervals[i].end);
                        break;

                    }
                }
                if(f==1){
                    ans++;
                    last.push_back(intervals[i].end);
                }
                sort(last.begin(),last.end());
            }
        }
        return ans;
        
    }
};
