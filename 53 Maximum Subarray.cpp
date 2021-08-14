class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int totalMax = nums[0];
        int currentMax = nums[0];
        int sum = 0;
        for(int i = 0 ;i<nums.size();i++) {
            sum += nums[i];
            currentMax = max(sum, currentMax);
            if(sum < 0) {
                totalMax = max(totalMax, currentMax);
                sum = 0;
            }
        }
        return max(totalMax, currentMax);
    }
};