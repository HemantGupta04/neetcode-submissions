class Solution {
public:
    int f(vector<int>&coins,int amount,int i,vector<vector<int>>&dp){
        int n=coins.size();
        if(amount==0)return 0;
        if(i>=n) return INT_MAX;
        if(dp[i][amount]!=-1) return dp[i][amount];
        int pick=INT_MAX;
        if(amount>=coins[i]){
            int am=f(coins,amount-coins[i],i,dp);
            if(am!=INT_MAX){
                pick=1+am;
            }
            else{
                pick=am;
            };
        }
        // return min(1+f(coins,amount-coins[i],i),f(coins,amount,i+1));
        int unpick=f(coins,amount,i+1,dp);

        return dp[i][amount]=min(pick,unpick);
    } 
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(coins,amount,0,dp);
        return ans==INT_MAX?-1:ans;
        
    }
};
