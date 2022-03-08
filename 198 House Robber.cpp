class Solution {
    int dp[101];
    int solve(vector<int> &nums, int pos) {
        if(pos >=  nums.size())
            return 0;
        if(dp[pos] != -1)
            return dp[pos];
        return dp[pos] = max(nums[pos] + solve(nums, pos+2), solve(nums, pos+1));
    }
public:
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums,0);
    }
};