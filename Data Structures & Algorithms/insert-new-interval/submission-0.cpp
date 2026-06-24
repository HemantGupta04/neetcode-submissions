class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        vector<vector<int>>newin;
        vector<vector<int>>ans;
        int f=0;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>newInterval[0]&&f==0 ){
                f=1;
                newin.push_back(newInterval);
            }
            newin.push_back(intervals[i]);
        }
        if(f==0){
            newin.push_back(newInterval);
        }
        // cout<<newin[1][0]<<endl;
        // cout<<newin[0][0]<<endl;
        for(int i=0;i<newin.size();i++){
            cout<<newin[i][0]<<" "<<newin[i][1]<<endl;;
        }
        cout<<endl;
        vector<int>cipher=newin[0];
        for(int i=1;i<n+1;i++){
            if(cipher[1]<newin[i][0]){
                ans.push_back(cipher);
            }
            else{
                newin[i][0]=min(cipher[0],newin[i][0]);
                newin[i][1]=max(cipher[1],newin[i][1]);

            }
            cipher=newin[i];
            
        }
        cout<<cipher[0]<<" "<<cipher[1];
        ans.push_back(cipher);

        // cout<<endl;

        return ans;
    }
};