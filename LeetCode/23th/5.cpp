// 1e3 f(i, j) = f(i + 1, j - 1)
class Solution {
private:
    static constexpr int N = 1e3 + 5;
    int dp[N][N];
    
public:
    string longestPalindrome(string s) {
        int ans = 0;
        memset(dp, 0, sizeof dp);
        int n = s.length();
        if (n == 0) return "";
        int f, e;
        for (int i = n - 1; i >= 0; i--)
            for (int j = i; j < n; j++){
                if (i == j) dp[i][i] = 1;
                else if (s[i] == s[j]){
                    if (i == j - 1) dp[i][j] = 1;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
                if (dp[i][j] && j - i + 1 > ans) 
                    f = i, e = j, ans = j - i + 1;
            }

        return s.substr(f, e - f + 1);
    }
};
