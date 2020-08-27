class Solution {
private:
    static constexpr int N = 15 + 5;
    int vis[N][N];
    int n, m, ans = 0;
    vector<vector<int>> grid;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    void dfs(int x, int y, int cur){
        vis[x][y] = 1;
        int nx, ny;
        int res = grid[x][y];
        for (int i = 0; i < 4; ++i){
            nx = dx[i] + x, ny = dy[i] + y;
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (!grid[nx][ny] || vis[nx][ny]) 
                ans = max(ans, cur + grid[x][y]);
            else dfs(nx, ny, cur + grid[x][y]);
        }
        vis[x][y] = 0;
    }
    
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        // DAG dp
        memset(vis, 0, sizeof(vis));
        n = grid.size(), m = grid[0].size();
        this->grid = grid;
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) {
                    memset(vis, 0, sizeof(vis));
                    dfs(i, j, 0);
                }
        }
        return ans;
    }
};
