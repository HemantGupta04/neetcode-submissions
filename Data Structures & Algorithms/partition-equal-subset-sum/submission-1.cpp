class Solution {
public:
   bool f(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
      int n=nums.size();
      if(sum==0) return true;
      if(i>=n) return false;
      if(dp[i][sum]!=-1) return dp[i][sum];
      if(sum>=nums[i]){
         return dp[i][sum]=f(i+1,sum-nums[i],nums,dp)|f(i+1,sum,nums,dp);
      }
      else{
        return dp[i][sum]=f(i+1,sum,nums,dp);
      }

   }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if(sum%2==0){
            sum/=2;
            return f(0,sum,nums,dp);

        }
        else{
            return false;
        }
        
    }
};
