class Solution {    
    void backTrack(vector<int>& candidates, int target, int sum, vector<vector<int> >&ans,  vector<int> &currentList, int pos) {
        if(sum > target) {
            return;
        }
        if(sum == target) {
            ans.push_back(currentList);
            return;
        }
        for(int i = pos; i< candidates.size();) {
            currentList.push_back(candidates[i]);
            backTrack(candidates, target, sum + candidates[i], ans, currentList, i + 1);
            currentList.pop_back();
            int cur = i;
            while(i < candidates.size() && candidates[i] == candidates[cur]) 
                i++;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> currentList;
        vector<vector<int> > ans;
        backTrack(candidates, target, 0, ans, currentList, 0);
        return ans;
    }
};