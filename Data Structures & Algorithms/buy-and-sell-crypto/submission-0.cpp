class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0,start=1e9,n=prices.size();

        for(int i=0;i<n;i++){
            if(prices[i]<start){
                start=prices[i];
            }
            else{
                ans=max(ans,prices[i]-start);
            }
        }

        return ans;

        
    }
};
