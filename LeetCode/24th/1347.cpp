#include <string>
using namespace std;

class Solution {
private:
    int cnt[26];
public:
    int minSteps(string s, string t) {
        memset(cnt, 0, sizeof cnt);
        int n = s.length(), ans = 0;
        for (int i = 0; i < n; i++) cnt[t[i] - 'a']++;
        for (int i = 0; i < n; i++){
            int c = s[i] - 'a';
            if (cnt[c] <= 0) ans++;
            else cnt[c]--;
        }
        return ans;
    }
};
