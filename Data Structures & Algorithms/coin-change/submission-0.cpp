class Solution {
public:
    int f(vector<int>&coins,int amount,int i){
        int n=coins.size();
        if(amount==0)return 0;
        if(i>=n) return INT_MAX;
        int pick=INT_MAX;
        if(amount>=coins[i]){
            int am=f(coins,amount-coins[i],i);
            if(am!=INT_MAX){
                pick=1+am;
            }
            else{
                pick=am;
            };
        }
        // return min(1+f(coins,amount-coins[i],i),f(coins,amount,i+1));
        int unpick=f(coins,amount,i+1);

        return min(pick,unpick);
    } 
    int coinChange(vector<int>& coins, int amount) {
        int ans=f(coins,amount,0);
        return ans==INT_MAX?-1:ans;
        
    }
};
