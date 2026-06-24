class Solution {
public:
    int f(int amount,vector<int>coins,int i,vector<vector<int>>&dp){
        int n=coins.size();
        if(amount==0)return 1;
        if(i>=n) return 0;

        if(dp[amount][i]!=-1) return dp[amount][i];
        int ans;
        if(amount>=coins[i]){
            ans=(f(amount-coins[i],coins,i,dp)+f(amount,coins,i+1,dp)); 
        }
        else{
            ans=f(amount,coins,i+1,dp);
        }
        return dp[amount][i]=ans;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(amount+1,vector<int>(n+1,-1));
        return f(amount,coins,0,dp);
        
    }
};
