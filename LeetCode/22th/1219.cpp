class Solution {
private:
    static constexpr int N = 15 + 5;
    int vis[N][N];
    int n, m, ans = 0;
    vector<vector<int>> grid;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    int dfs(int x, int y){
        vis[x][y] = 1;
        int nx, ny;
        int res = grid[x][y];
        for (int i = 0; i < 4; ++i){
            nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!grid[nx][ny] || vis[nx][ny]) continue;
            res = max(grid[x][y] + dfs(nx, ny), res);
        }
        // printf("(%d, %d, %d)", x, y, res);
        vis[x][y] = 0; // 回溯取消该点标记
        return res;
    }
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // DAG dp
        memset(vis, 0, sizeof(vis));
        n = grid.size(), m = grid[0].size();
        this->grid = grid;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (grid[i][j])  ans = max(ans, dfs(i, j));
                
        return ans;
    }
};
