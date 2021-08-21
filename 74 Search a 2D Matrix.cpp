class Solution {
    int binarySearch(int target, int high, int row, int col, vector<vector<int>>& matrix) {
        int low = 0;
        while(low < high) {
            int mid = (low + high) / 2;
            
            int val = (row == -1) ? matrix[mid][col] : matrix[row][mid];
            if(val == target)
                return mid;
            if(val > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n == 0)
            return false;
        int m = matrix[0].size();
        if(m == 0)
            return false;
        int row = binarySearch(target, n - 1, -1, 0, matrix);
        if(row >= n || matrix[row][0] > target)
            row--;
        if(row < 0)
            row++;
        int col = binarySearch(target, m - 1, row, -1, matrix);
        if(col >= m)
            col--;
        if(col < 0)
            col++;
        return matrix[row][col] == target;
    }
};