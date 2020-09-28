#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int maxProfit(vector<int>& p) {
        n = p.size();
        dp.resize(n, vector<int>(2, 0));
        
        dp[0][0] = 0, dp[0][1] = -p[0];
        for (int i = 1; i < n; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + p[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - p[i]);
        }
        return dp[n - 1][0];
    }
};