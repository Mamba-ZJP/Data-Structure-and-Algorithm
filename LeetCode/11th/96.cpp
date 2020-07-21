class Solution {
private:
    vector<int> memo;
public:
    int numTrees(int n) {
        // memo.resize(n + 1, -1);
        // return f(n);
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 0; j <= i - 1; ++j) {
                dp[i] += (dp[j] * dp[i - j - 1]);
            }
        }


        return dp[n];
    }

    int f(int n){
        if(n <= 1) return 1;
        if(memo[n] != -1) return memo[n];
        int sum = 0;
        for(int i = 1; i <= n; ++i) {
            sum += (f(i - 1) * f(n - i));
        }
        return memo[n] = sum;
    }
};
