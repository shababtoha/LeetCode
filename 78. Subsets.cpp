class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector< vector<int> > ans;
        int totAns = 1 << (nums.size());
        for(int i = 0; i < totAns; i++) {
            vector<int> subSet;
            int index = 0;
            int n = i;
            int cnt = 0;
            while(n > 0) {
                int bit = n & 1;
                if(bit) {
                    subSet.push_back(nums[cnt]);
                }
                cnt++;
                n = n >> 1;
            }
            ans.push_back(subSet);
        }
        return ans;
    }
};