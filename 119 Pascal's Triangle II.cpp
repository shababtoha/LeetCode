class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> lastRow = {1};   
        for(int i = 0 ; i< rowIndex; i++) {
            vector<int> v;
            v.push_back(1);
            for(int j = 1; j<lastRow.size(); j++) {
                v.push_back(lastRow[j] + lastRow[j-1]);
            }
            v.push_back(1);
            lastRow = v;
        }
        return lastRow;
    }
};