class Solution {
public:
    int f(int i,vector<int>&prices,int chk,vector<vector<int>>&dp){
        if(i>=prices.size())return 0;
        if(dp[i][chk]!=-1) return dp[i][chk];

        if(chk==0){
            return  dp[i][chk]=max(-prices[i]+f(i+1,prices,1,dp),f(i+1,prices,0,dp));
        }
        else{
            return dp[i][chk]=max(prices[i]+f(i+2,prices,0,dp),f(i+1,prices,1,dp));
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(0,prices,0,dp);
        
    }
};
