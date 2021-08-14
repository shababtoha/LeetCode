class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n == 0) {
            return 0;
        }
        int m = obstacleGrid[0].size();
        if(m == 0) {
            return 0;
        }
        
        vector<vector<long long>> dp(n, vector<long long>(m, 0));
        dp[n-1][m-1] = !obstacleGrid[n-1][m-1];
        for(int row = n-1; row>=0; row--) {
            for(int col = m-1; col >=0; col--) {
                if(!obstacleGrid[row][col] && row + 1 < n) {
                    dp[row][col] += dp[row+1][col];
                }
                if(!obstacleGrid[row][col] && col + 1 < m) {
                    dp[row][col]+= dp[row][col+1];
                }
            }
        }
        
        return dp[0][0];
    }
};