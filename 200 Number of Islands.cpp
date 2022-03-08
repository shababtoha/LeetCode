class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    void dfs(vector<vector<char>>& grid, int n, int m, int x, int y) {
        if(x < 0 || y < 0 || x == n || y == m)
            return;
        if(grid[x][y] != '1')
            return;
        grid[x][y] = '#';
        for(int i = 0 ; i<4; i++) {
            dfs(grid, n, m, x + dx[i], y + dy[i]);
        }
        return;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i = 0 ; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    dfs(grid, n, m, i, j);
                }
            }
        }
        return ans;
    }
};