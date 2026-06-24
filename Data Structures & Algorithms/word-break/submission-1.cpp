class Solution {
public:
    bool f(int i,string&s, vector<string>& wordDict,vector<int>&dp){
        int n=s.size();
        int m=wordDict.size();
        if(i==n) return true;
        if(dp[i]!=-1)return dp[i];
        bool ans=false;
        for(int k=0;k<m;k++){
            if(s.substr(i,wordDict[k].size())==wordDict[k]){
                ans|=f(i+wordDict[k].size(),s,wordDict,dp);
                
            }
        }
        return dp[i]=ans;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>dp(s.size(),-1);
        return f(0,s,wordDict,dp);
        
    }
};
