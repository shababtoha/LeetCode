class Solution {
    bool taken[6];
    void backTrack(vector<int>& nums, vector<int> &curlist, vector<vector<int>> &ans) {
        if(nums.size() == curlist.size()) {
            ans.push_back(curlist);
            return;
        }
        for(int i = 0 ; i< nums.size();i++) {
            if(taken[i])
                continue;
            taken[i] = true;
            curlist.push_back(nums[i]);
            backTrack(nums, curlist, ans);
            curlist.pop_back();
            taken[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
         memset(taken, false, sizeof(taken));
         vector<int> curlist;
         vector<vector<int>> ans;
         backTrack(nums, curlist, ans);
         return ans;
    }
};