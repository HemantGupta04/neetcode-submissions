class Solution {
public:
    int ans=0;
    void f(vector<int>&nums,int i,int target,int sum){
        int n=nums.size();
        // int ans=0;
        if(i>=n){
            if(target==sum){
                ans++;
            }
            return ;
        }

        f(nums,i+1,target,sum+nums[i]);
        f(nums,i+1,target,sum-nums[i]);
        

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        f(nums,0,target,0);
        return ans;
        
    }
};
