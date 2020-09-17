#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    string sortString(string s) {
        int n = s.length();
        sort(s.begin(), s.end());
        string ans = "";
        int cnt = 0;
        while (cnt < n){
            char pre = '#';
            for (int i = 0; i < n; i++){
                if (s[i] == '#') continue;
                if (pre == '#' || s[i] > pre) 
                     ans += s[i], pre = s[i], s[i] = '#', cnt++;
            }

            pre = '#';
            for (int i = n - 1; i >= 0; i--){
                if (s[i] == '#') continue;
                if (pre == '#' || s[i] < pre) 
                    ans += s[i], pre = s[i], s[i] = '#', cnt++;
            }
        }

        return ans;
    }
};