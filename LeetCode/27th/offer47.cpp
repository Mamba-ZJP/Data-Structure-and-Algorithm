#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    int n, m;
public:
    int maxValue(vector<vector<int>>& G) {
        n = G.size(), m = G[0].size();
        dp.resize(n + 1, vector<int> (m + 1, 0));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + G[i - 1][j - 1];
            }
        }
        return dp[n][m];
    }
};