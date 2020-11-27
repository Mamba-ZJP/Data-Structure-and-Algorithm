// 1e4 prefix
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length(), ans = 0;
        for (int i = 1; i <= n; i++) {
            pre[i][s[i - 1] - 'a']++; 
            for (int j = 0; j < 26; j++) pre[i][j] += pre[i - 1][j];
        }

        for (int i = k; i <= n; i++) {
            for (int j = 1; j <= (i - k + 1); j++) {
                bool flag = true;
                for (int m = 0; m < 26; m++) {
                    int cnt = pre[i][m] - pre[j - 1][m];
                    if (cnt == 0) continue;
                    if (cnt < k) {
                        flag = false; break;
                    }
                }

                if (flag && (i - j + 1 > ans)) 
                    ans = i - j + 1;
            }
        }

        return ans;
    }
private:
    static constexpr int MAXN = 1e4 + 5;
    int pre[MAXN][26];
};