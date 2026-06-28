class Solution {
public:
    int trap(vector<int>& height) {

        int n=height.size(),p=-1;
        vector<int>pre(n),suf(n);

        for(int i=0;i<n;i++){
            pre[i]=max(height[i],p);
            p=pre[i];
        }
        p=-1;
        for(int i=n-1;i>=0;i--){
            suf[i]=max(height[i],p);
            p=suf[i];
        }

        int ans=0;
        for(int i=1;i<n-1;i++){
            ans+=(min(pre[i],suf[i])-height[i]);

        }

        return ans;
        
    }
};
