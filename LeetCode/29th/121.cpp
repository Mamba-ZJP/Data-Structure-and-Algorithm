#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int maxProfit(vector<int>& p) {
        n = p.size();
        int mi = INT_MAX, ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, p[i] - mi);
            mi = min(mi, p[i]);
        }
        return max(ans, 0);
    }
};