class Solution {
    int binarySc(vector<int>& nums, int target, bool isUpper) {
        int low = 0;
        int high = nums.size() -1;
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) >> 1;
            if(nums[mid] == target) {
                ans = mid;
                if(isUpper) {
                    low = mid + 1;
                } else {
                    high = mid -1;
                }
            } else if(target < nums[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        ans.push_back(binarySc(nums, target, false));
        ans.push_back(binarySc(nums, target, true));
        return ans;
    }
};