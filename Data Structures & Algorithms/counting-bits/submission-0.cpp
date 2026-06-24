class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0;i<n+1;i++){
            int num=i;
            int c=0;
            while(num){
                c+=(num&1);
                num/=2;
            }
            ans[i]=c;
        }
        return ans;
        
    }
};
