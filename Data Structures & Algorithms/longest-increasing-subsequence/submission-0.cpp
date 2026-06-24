class Solution {
public:
    // int f(int i,vector<int>&nums){
    //     for(int i=0)

    // }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n);
        dp[n-1]=1;
        for(int i=n-2;i>=0;i--){
            int c=0;
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]){
                    c=max(c,dp[j]);

                }
            }
            dp[i]=1+c;
            cout<<dp[i]<<endl;

        }
        return *max_element(dp.begin(),dp.end());

        
    }
};
