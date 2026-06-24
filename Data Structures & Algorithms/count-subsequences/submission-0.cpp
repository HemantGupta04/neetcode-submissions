class Solution {
public:
    int f(const string &s,const string &t,int i,int j,vector<vector<int>>&dp){
        int n=s.size();
        int m=t.size();
        int ans=0;
        if(j>=m) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(int k=i;k<n;k++){
            if(s[k]==t[j]){
                ans+=f(s,t,k+1,j+1,dp);
            }
        }
        return dp[i][j]=ans;
    }
    int numDistinct(string s, string t) {

        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(s,t,0,0,dp);
        
    }
};
