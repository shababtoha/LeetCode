class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector< vector<int> > dp(n , vector<int>(m, 0));
        for(int i = n-1; i>=0; i--) {
            for(int j = m-1; j>=0; j--){
                if(i == n-1 && j == m-1) {
                    dp[i][j] = (dungeon[i][j] >= 0) ? 0 : -dungeon[i][j];
                    continue;
                }
                int needRight = 10000000;
                int needDown = 10000000;
                if(j + 1 < m) {
                    needRight = dp[i][j + 1];
                }
                if(i + 1 < n) {
                    needDown = dp[i+1][j];
                }
                int mn = min(needRight, needDown);
                if(dungeon[i][j] < 0) {
                    dp[i][j] = -dungeon[i][j] + mn;
                } else {
                    dp[i][j] = dungeon[i][j] - mn;
                    dp[i][j] = dp[i][j] >=0 ? 0 : -dp[i][j];
                }
            }
        }
        return dp[0][0] + 1;
    }
};