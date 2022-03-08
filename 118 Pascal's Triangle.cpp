class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector< vector<int> > ans;
        vector<int> oneVector = {1};
        ans.push_back(oneVector);    
        if(numRows == 1) {
            return ans;
        }
       
        for(int i = 2 ; i<= numRows; i++) {
            vector<int> v;
            v.push_back(1);
            vector<int> lastRow = ans.back();
            for(int i = 1; i<lastRow.size(); i++) {
                v.push_back(lastRow[i] + lastRow[i-1]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};