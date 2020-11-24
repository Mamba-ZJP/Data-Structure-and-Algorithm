// dp(i, 0) <= max{dp(i - 1, 1), dp(i - 1, 0)}
// dp(i, 1) <= dp(i - 1, 0) + v[i]
class Solution {
public:
    int massage(vector<int>& nums) {
        int n = nums.size();
        if (!n) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        dp[0][0] = 0, dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};