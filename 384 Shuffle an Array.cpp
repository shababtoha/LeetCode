class Solution {
    vector<int> orig;
public:
    Solution(vector<int>& nums) {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result(orig);
        for (int i = 0;i < result.size();i++) {
            int pos = rand()%(result.size()-i);
            swap(result[i+pos], result[i]);
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */