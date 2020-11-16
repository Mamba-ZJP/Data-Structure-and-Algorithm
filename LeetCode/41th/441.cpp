#define LL long long
class Solution {
public:
    int arrangeCoins(int n) {
        LL l = 1, r = n;
        while (l < r) {
            LL m = (l + r + 1) >> 1;
            if (isValid(m, n)) l = m;
            else r = m - 1;
        }
        return r;
    }
private:
    inline bool isValid(int m, int n) {
        return ((1LL + m) * m / 2) <= n;
    }
};