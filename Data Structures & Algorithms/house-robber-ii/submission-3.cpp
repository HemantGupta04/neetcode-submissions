class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];  // Special case: Only one house
        
        // DP for case 1: Exclude the last house
        vector<int> dp(n-1);
        for (int i = 0; i < n-1; i++) {
            if (i == 0) dp[i] = nums[i];
            else if (i == 1) dp[i] = max(nums[i], nums[i-1]);
            else {
                dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
            }
        }

        // DP for case 2: Exclude the first house
        vector<int> dp2(n-1);
        for (int i = 1; i < n; i++) {
            if (i == 1) dp2[i-1] = nums[i];
            else if (i == 2) dp2[i-1] = max(nums[i], nums[i-1]);
            else {
                dp2[i-1] = max(nums[i] + dp2[i-3], dp2[i-2]);
            }
        }

        // Return the maximum of both cases
        return max(dp[n-2], dp2[n-2]);
    }
};
