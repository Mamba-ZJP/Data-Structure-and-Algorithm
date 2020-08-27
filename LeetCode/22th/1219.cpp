#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<climits>
#define x first
#define y second
#define MP make_pair
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;


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
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j)
                if (grid[i][j]) {
                    memset(vis, 0, sizeof(vis));
                    ans = max(ans, dfs(i, j));
                }
        }
        return ans;
    }
};

// int main(void){
//     Solution a;
//     vector<vector<int>> t = {
//         {0,6,0},
//         {5,8,7},
//         {0,9,0},
//     };
//     a.getMaximumGold(t);
// }

// [
// [0,0,0,0,0,0,32,0,0,20],  // 58 + 36 = 94 + 20 = 114 + 13 = 127
// [0,  0, 2,0,0,0,0,40,0,32],
// [13,20,36,0, 0,0,20,0,0,0],
// [0, 31,27,0,19,0,0,25,18,0],
// [0,0,0,0,0,0,0,0,0,0],
// [0,0,0,0,0,0,0,18,0,6],
// [0,0,0,25,0,0,0,0,0,0],
// [0,0,0,21,0,30,0,0,0,0],
// [19,10,0,0,34,0,2,0,0,27],
// [0,0,0,0,0,34,0,0,0,0]
// ]
