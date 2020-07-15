class Solution {
public:
    int reverse(int x) {
        int ans = 0;
        int mx = pow(2,31) - 1, mi = pow(-2,31);
        while(x != 0) {
            int carry = x % 10;
            if(ans > mx/10 || (ans == mx/10 && carry > 7)) return 0;
            if(ans < mi/10 || (ans == mi/10 && carry < -8)) return 0;             
            ans = ans * 10 + carry;
            x /= 10;
        }
        return ans;
    }
    //-2147483412
};
