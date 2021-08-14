class Solution {
    void backTrack(vector<int>& candidates, int target, int sum, vector<vector<int> >&ans,  vector<int> &currentList, int pos) {
        if(pos >= candidates.size()) {
            return;
        }
        if(sum > target) {
            return;
        }
        if(sum == target) {
            ans.push_back(currentList);
            return;
        }
        for(int i = pos; i< candidates.size(); i++) {
            currentList.push_back(candidates[i]);
            backTrack(candidates, target, sum + candidates[i], ans, currentList, i);
            currentList.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentList;
        vector<vector<int> > ans;
        backTrack(candidates, target, 0, ans, currentList, 0);
        return ans;
    }
};