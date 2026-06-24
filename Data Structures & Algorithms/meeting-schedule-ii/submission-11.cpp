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
    // static bool comp(Interval a,Interval b){
    //     return a.start<b.start;
    // }
    int minMeetingRooms(vector<Interval>& intervals) {
        int n=intervals.size();
        if(n==0) return 0;
        vector<int>one(n);
        vector<int>two(n);
        // sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<n;i++){
            one[i]=intervals[i].start;
            two[i]=intervals[i].end;
        }
        sort(one.begin(),one.end());
        sort(two.begin(),two.end());
        int i=1;
        int j=0;
        int ans=1;
        int count=1;
        while(i<n && j<n){
            if(one[i]<two[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            ans=max(ans,count);

        }
        return ans;


        
    }
};
