class Solution {
public:
    int f(string s,int i,vector<int>&dp){
        int n=s.size();

        if(i==n){
            return 1;
        }
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans;
        if(s[i]=='0') ans=0;
        else if(s[i]=='1'){
            if(i+1>n && s[i+1]=='0'){
                ans=f(s,i+2,dp);
            }
            else{
                ans=f(s,i+1,dp)+f(s,i+2,dp);
            }
        }
        else if(s[i]=='2'){
            if(i+1<n && s[i+1]=='0'){
                ans=f(s,i+2,dp);
            }
            else if(i+1<n && s[i+1]>'0'&& s[i+1]<='6'){
                ans=f(s,i+1,dp)+f(s,i+2,dp);
            }
            else{
                ans=f(s,i+1,dp);
            }
        }
        else{
            ans=f(s,i+1,dp);
        }
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.size();

        vector<int>dp(n,-1);

        return f(s,0,dp);
        
    }
};
