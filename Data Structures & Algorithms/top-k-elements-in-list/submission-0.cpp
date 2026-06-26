class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n=nums.size();
        for(auto i:nums){
            m[i]++;
        }
        vector<int>ans;
        vector<vector<int>>freq(n+1);
        for(auto [i,j]:m){
            freq[j].push_back(i);
        }

        for(int i=n;i>=0;i--){
            for(int j=0;j<freq[i].size();j++){
                if(ans.size()>=k)break;
                ans.push_back(freq[i][j]);
            }
        }
        return ans;
        
    }
};
