class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=-100000;
        vector<int>pro;
        for(int i=0;i<n;i++){
            pro.push_back(nums[i]);
            int num=nums[i];
            for(int j=i+1;j<n;j++){
                num*=nums[j];
                pro.push_back(num);
            }
            // ans=max(ans,pro);
        }
        for(int i=0;i<pro.size();i++){
            ans=max(ans,pro[i]);
        }
        
        return ans;

        
    }
};
