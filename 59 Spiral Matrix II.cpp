class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int> > matrix (n, vector<int>(n));
        int totalSize = n * n;
        int row = 0;
        int col = 0;
        int rowDone = 0;
        int colDone = 0;
        int rowDir = 1;
        int colDir = 1;
        int cnt = 1;
        while(cnt -1 < totalSize) {
            for(int i = 0; i < n - colDone; i++) {
                matrix[row][col] = cnt++;
                col = col + colDir;
            }
            rowDone++;
            row+=rowDir;
            colDir = -colDir;
            col += colDir;
            for(int i = 0; i < n - rowDone; i++) {
                matrix[row][col] = cnt++;
                row = row + rowDir;
            }
            col+=colDir;
            colDone++;
            rowDir = -rowDir;
            row += rowDir;
        }
        return matrix;
    }
};