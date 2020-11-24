#define LL long long
const LL mod = 1e9 + 7;

int dp[55][55][255];

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        this->m = m, this->n = n, this->N = N;
        memset(dp, -1, sizeof(dp));
        return dfs(i, j, N);
    }
private:
    int m, n, N;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
    int dfs(int x, int y, int N) {
        if (N < 0) return 0;
        if (x < 0 || x >= m || y < 0 || y >= n) return 1;
        int &c = dp[x][y][N];
        if (c != -1) return c;
        
        c = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            c += dfs(nx, ny, N - 1), c %= mod;
        }

        return c;
    }
};