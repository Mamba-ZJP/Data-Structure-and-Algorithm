#define LL long long
const LL mod = 1000000007;
class Solution {
public:
    int waysToStep(int n) {
        LL a = 1, b = 2, c = 4, d, lev = 4;
        if (n <= 2) return n;
        if (n == 3) return 4;
        while (lev <= n) {
            d = (a + b + c) % mod;
            a = b, b = c, c = d, lev++;
        }

        return (int)d;
    }
};