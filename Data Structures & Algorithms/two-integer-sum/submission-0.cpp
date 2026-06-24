class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int,int>m;
        int n=nums.size();

        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            int idx=target-nums[i];
            if(m.count(idx)==1 and i!=m[idx])return {min(i,m[idx]),max(i,m[idx])};
        }
        
    }
};
