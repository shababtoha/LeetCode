class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) {
            ans.push_back(newInterval);
            return ans;
        }
        int intervalStart = -1;
        int intervalEnd = -1;
        if(newInterval[0] < intervals[0][0]) {
            intervalStart = newInterval[0];
            intervalEnd = newInterval[1];
        } else {
            intervalStart = intervals[0][0];
            intervalEnd = intervals[0][1];
        }
        if(newInterval[0] > intervals.back()[0]) {
            intervals.push_back(newInterval);
        }
        for(int i = 0 ;i<intervals.size(); i++) {
            if(intervalEnd >= newInterval[0]) {
                intervalEnd = max(intervalEnd, newInterval[1]);
            }
            if(intervalEnd >= intervals[i][0]) {
                intervalEnd = max(intervalEnd, intervals[i][1]);
            } else {
                ans.push_back(vector<int>{intervalStart, intervalEnd});
                if(newInterval[0] > intervalEnd && newInterval[0] <= intervals[i][0]) {
                    intervalStart = newInterval[0];
                    intervalEnd = newInterval[1];
                    i--;
                } else {
                    intervalStart =intervals[i][0];
                    intervalEnd = intervals[i][1];
                }
            }
        }
        ans.push_back(vector<int>{intervalStart, intervalEnd});
        return ans;
    }
};