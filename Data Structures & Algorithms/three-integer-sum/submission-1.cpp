class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            int var=nums[i];
            if(i>=1 and nums[i]==nums[i-1]) continue;
            int l=i+1,r=n-1;
            while(l<r){
                if(var+nums[l]+nums[r]==0){
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r and nums[l]==nums[l-1])l++;
                }
                else if(nums[l]+nums[r]>-var){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
        
    }
};
