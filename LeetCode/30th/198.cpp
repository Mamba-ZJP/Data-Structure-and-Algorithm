#include <vector>
#include <algorithm>
using namespace std;

int dp[105];
// f(i) = max(f(i - 1), f(i - 2) + a[i])
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        dp[0] = 0, dp[1] = nums[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp[n];
    }
};