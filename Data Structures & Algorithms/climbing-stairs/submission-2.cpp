class Solution {
public:
    int climbStairs(int n) {
        int prev1=1;
        int prev2=1;
        int ans=1;
        // vector<int>dp(n+1);
        // dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            // dp[i]=dp[i-1]+dp[i-2];
            ans=prev1+prev2;
            prev1=prev2;
            prev2=ans;
        }
        return ans;


        
    }
};
