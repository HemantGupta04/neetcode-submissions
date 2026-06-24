class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end());
        vector<int>cipher=intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(cipher[1]<intervals[i][0]){
                ans.push_back(cipher);
            }
            else{
                intervals[i][0]=min(cipher[0],intervals[i][0]);
                intervals[i][1]=max(cipher[1],intervals[i][1]);

            }
            cipher=intervals[i];
            
        }
        cout<<cipher[0]<<" "<<cipher[1];
        ans.push_back(cipher);

        // cout<<endl;

        return ans;
        
    }
};
