class Solution {
public:
    int f(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&dp){
        int n=matrix.size();
        int m=matrix[0].size();

        if(dp[i][j]!=-1)return dp[i][j];
        
        // if(i-1<0 || j-1<0 || i+1>=n || j+1>=m) return 0;
        int ans=1;
        if(i-1>=0 && matrix[i][j]<matrix[i-1][j]){
            ans=max(ans,1+f(matrix,i-1,j,dp));
        }
        if(j-1>=0 && matrix[i][j]<matrix[i][j-1]){
            ans=max(ans,1+f(matrix,i,j-1,dp));
        }
        if(i+1<n && matrix[i][j]<matrix[i+1][j]){
            ans=max(ans,1+f(matrix,i+1,j,dp));
        }
        if(j+1<m && matrix[i][j]<matrix[i][j+1]){
            ans=max(ans,1+f(matrix,i,j+1,dp));
        }
        // cout<<i<<" "<<j<<" "<<ans<<endl;
        return dp[i][j]=ans;


    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int num=f(matrix,i,j,dp);
                // cout<<num<<" ";
                ans=max(ans,num);
            }
        }
        // int num=f(matrix,1,0);
        // cout<<num<<endl;
        return ans;
        
    }
};
