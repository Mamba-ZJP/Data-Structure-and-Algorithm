#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    static constexpr int N = 1000 + 5;
    int n;
    int dp[N]; 
public:
    int minCostClimbingStairs(vector<int>& cost) {
        n = cost.size();
        int a, b, c;
        a = b = c = 0;
        for (int i = 2; i <= n; i++){
            c = min(a + cost[i - 2], b + cost[i - 1]);
            a = b, b = c;
        }
        return c;
        // dp[0] = dp[1] = 0;
        // for (int i = 2; i <= n; i++){
        //     dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        // }
        // return dp[n];
    }
};