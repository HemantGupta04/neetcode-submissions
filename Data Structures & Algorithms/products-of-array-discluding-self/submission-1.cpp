class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int>ans(n);
        int p=1;
        for(int i=0;i<n;i++){
            ans[i]=p;
            p=ans[i]*nums[i];
            cout<<ans[i]<<" ";
        }
        p=1;
        for(int i=n-1;i>=0;i--){

            ans[i]*=p;
            p*=nums[i];
        }

        // for(int i=1;i<n-1;i++){
        //     ans[i]=pre[i-1]*suf[i+1];
        // }
        // ans[0]=suf[1];
        // ans[n-1]=pre[n-2];
        return ans;


    }
};
