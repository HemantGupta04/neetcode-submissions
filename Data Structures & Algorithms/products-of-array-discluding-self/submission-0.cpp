class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int>pre(n),suf(n),ans(n);
        int p=1;
        for(int i=0;i<n;i++){
            pre[i]=p*nums[i];
            p=pre[i];
        }
        p=1;
        for(int i=n-1;i>=0;i--){
            suf[i]=p*nums[i];
            p=suf[i];
        }

        for(int i=1;i<n-1;i++){
            ans[i]=pre[i-1]*suf[i+1];
        }
        ans[0]=suf[1];
        ans[n-1]=pre[n-2];
        return ans;


    }
};
