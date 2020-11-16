#define LL long long
class Solution {
public:
    int mySqrt(int x) {
        LL l = 1, r = x;
        while (l < r) {
            LL m = (l + r + 1) >> 1;
            if (m * m > x) r = m - 1;
            else l = m;
        }
        return (int)r;
    }
};