class Solution {
public:
    static bool comp(vector<int>a,vector<int>b){
        return a[1]<b[1];
    } 
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end(),comp);
        int ans=0;
        vector<int>ref=intervals[0];
        for(int i=1;i<n;i++){
            // cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            if(ref[1]<=intervals[i][0]){
                ref=intervals[i];
            }
            else{
                ans++;

            }
        }
        return ans;
    }
};