// dp(i, 0) 表示没选第1个 dp(i, 1) 表示选了第一个
// dp(i, 0) = max(dp(i - 1, 0), dp(i - 2, 0) + n[i])
// dp(i, 1) = max(dp(i - 1, 1), dp(i - 2, 1) + n[i])
// dp(1, 0) = 0  dp(1, 1) = nums[0] 
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    int n;
    vector<int> dp;
public:
    int rob(vector<int> &nums) {
        n = nums.size();
        dp.resize(n + 1, 0);
        // 先从第 1 件选到第 n - 1 件
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        dp[1] = nums[0];
        for (int i = 2; i <= n - 1; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        
        int res = dp[n - 1];
        dp[1] = 0, dp[2] = nums[1];
        for (int i = 3; i <= n; i++)
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        
        return max(res, dp[n]);
    }
    // int rob(vector<int>& nums) {
    //     n = nums.size();
    //     if (n == 0) return 0;
    //     if (n <= 1) return nums[0];
    //     vector<vector<int>> dp;
    //     dp.resize(n + 1, vector<int> (2, 0));
    //     dp[1][0] = 0, dp[1][1] = nums[0];
    //     for (int i = 2; i <= n; i++) {
    //         int a = nums[i - 1];
    //         dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + a);

    //         if (i != n)
    //             dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + a);
    //         else dp[i][1] = dp[i - 1][1];
    //     }
    //     return max(dp[n][0], dp[n][1]);
    // }
};