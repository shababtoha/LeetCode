class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        if(n == 0) 
            return ans;
        int m = matrix[0].size();
        if(m == 0) 
            return ans;
        int totalSize = n * m;
        int row = 0;
        int col = 0;
        int rowDone = 0;
        int colDone = 0;
        int rowDir = 1;
        int colDir = 1;
        while(ans.size() != totalSize) {
            for(int i = 0; i < m- colDone; i++) {
                ans.push_back(matrix[row][col]);
                col = col + colDir;
            }
            rowDone++;
            row+=rowDir;
            colDir = -colDir;
            col += colDir;
            for(int i = 0; i < n - rowDone; i++) {
                ans.push_back(matrix[row][col]);
                row = row + rowDir;
            }
            col+=colDir;
            colDone++;
            rowDir = -rowDir;
            row += rowDir;
        }
        return ans;
    }
};