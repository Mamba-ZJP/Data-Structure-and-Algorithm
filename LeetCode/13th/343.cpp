class Solution {
public:
   

    int integerBreak(int n) {
        if (n <= 3) return n - 1; 
        int x = n / 3, y = n % 3; 
        if (y == 1) return (int) pow(3, x - 1) * 4; 

        if (y == 0) return (int)pow(3, x); 
        return (int) pow(3, x) * 2;

    }
};
