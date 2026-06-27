class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;

        for(int i=0;i<n;i++){
            if(mp.count(nums[i]-1)==0){
                int num=nums[i];
                int temp=0;
                while(mp.count(num)!=0){
                    num++;
                    temp++;
                }
                ans=max(ans,temp);
            }
        }
        return ans;

        
    }
};
