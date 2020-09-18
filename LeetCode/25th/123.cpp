#include <vector>
#include <algorithm>
using namespace std;
// dp(i, j, k) 表示在第 i 天手里是否有股票（0无，1有）做了 k 次交易赚的最大利润
// 初始化也要初始化交易了两次的初始值，否则后面递推的时候：
// dp(i, 0, 2) 由 dp(i - 1, 1, 2) + p[i] 转移来时， 实际上还没有做第二次交易的买入，此时应该无法直接卖出
class Solution {
private:
    static constexpr int N = 1e5 + 5;
    int dp[N][2][3];
    int n;
public:
    int maxProfit(vector<int>& p) {
        n = p.size();
        memset(dp, 0, sizeof dp);
        dp[0][0][0] = 0, dp[0][1][1] = dp[0][1][2] = -p[0];

        for (int i = 1; i < n; i++){
            for (int j = 1; j <= 2; j++){
                dp[i][0][j] = max(dp[i - 1][0][j], dp[i - 1][1][j] + p[i]);
                dp[i][1][j] = max(dp[i - 1][1][j], dp[i - 1][0][j - 1] - p[i]);
            }
        }
        return max(dp[n - 1][0][1], dp[n - 1][0][2]);
    }
};