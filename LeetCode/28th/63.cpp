#include <vector>
using namespace std;

// 0 is empty space / 1 is an obstacle
class Solution {
private:
    int n, m;
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        n = ob.size(), m = ob[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (ob[i][j] == 1) dp[i][j] = 0;
                else {
                    if (!i && !j) continue;
                    else if (j && !i) dp[0][j] = dp[0][j - 1];
                    else if (i && !j) dp[i][0] = dp[i - 1][0];
                    else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[n - 1][m - 1];
    }
};