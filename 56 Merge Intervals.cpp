class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int intervalStart = intervals[0][0];
        int intervalEnd = intervals[0][1];
        for(int i = 0; i < intervals.size(); i++) {
            if(intervalEnd >= intervals[i][0]) {
                intervalEnd = max(intervalEnd, intervals[i][1]);
            } else {
                ans.push_back(vector<int>{intervalStart,intervalEnd});
                intervalStart =  intervals[i][0];
                intervalEnd =  intervals[i][1];
            }
        }
        ans.push_back(vector<int>{intervalStart,intervalEnd});
        return ans;
    }
};