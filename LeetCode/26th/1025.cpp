#include <vector>
using namespace std;
// 谁先面对1 谁gg  A先手只要让对面进入面对 1 的局面
class Solution {
public:
    bool divisorGame(int N) {
        int dp[1010]; // dp(i) 表示先手面对点数为 i 的局面赢不赢
        memset(dp, 0, sizeof(dp));
        dp[1] = 0, dp[2] = 1, dp[3] = 0; 
        if (N <= 3) return dp[N];
        // dp(i) 只要有一次赢对面(对面输) 就赢了
        for (int i = 4; i <= N; i++){
            for (int j = 1; j < i; j++){
                if (i % j != 0) continue;
                dp[i] = dp[i] || (!dp[i - j]);
                if (dp[i]) break;
            }
        }
        return dp[N];
    }
};