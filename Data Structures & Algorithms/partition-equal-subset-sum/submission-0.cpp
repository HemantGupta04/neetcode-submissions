class Solution {
public:
   bool f(int i,int sum,vector<int>&nums){
      int n=nums.size();
      if(sum==0) return true;
      if(i>=n) return false;

      if(sum>=nums[i]){
         return f(i+1,sum-nums[i],nums)|f(i+1,sum,nums);
      }
      else{
        return f(i+1,sum,nums);
      }

   }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==0){
            sum/=2;
            return f(0,sum,nums);

        }
        else{
            return false;
        }
        
    }
};
