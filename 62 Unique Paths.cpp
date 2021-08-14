class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = 1;
        for(int row = n-1; row>=0; row--) {
            for(int col = m-1; col >=0; col--) {
                if(row + 1 < n) {
                    dp[row][col] += dp[row+1][col];
                }
                if(col + 1 < m) {
                    dp[row][col]+= dp[row][col+1];
                }
            }
        }
        
        return dp[0][0];
    }
};