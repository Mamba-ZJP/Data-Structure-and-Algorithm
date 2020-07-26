class Solution {
public:
    int memo[59];
    int dfs(int n){
        if(n <= 2) return 1;
        if(memo[n] != -1) return memo[n];
        int t = 1;
//枚举所有情况 f(n)=max{i * f(n - i), i * (n-i)} (1 <= i <= n-1)
//当我枚举了当前n的可拆分的第一个数字i的时候，整数n-i可以分成哪些数，就是一个更小的子问题了，注意在这里答案也有可能只有两个数
        for(int i = 1; i <= n - 1; ++i){
            t = max(t, max(i * dfs(n - i), i * (n - i)));
        }
        return memo[n] = t;
    }

    int integerBreak(int n) {
        memset(memo, -1, sizeof memo);
        // return dfs(n); //自顶向下

        //自底向上
        memo[1] = memo[2] = 1;
        //memo[n]表示给定数字为n的最大值
        for(int i = 3; i <= n; ++i){
            int & t = memo[i];
            for(int j = 1; j < i; ++j){
                t = max(t, max(memo[i - j] * j, j * (i - j)));
            }
        }

        return memo[n];
    }
};
