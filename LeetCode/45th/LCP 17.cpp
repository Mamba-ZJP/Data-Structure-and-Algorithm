class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        int x = 1, y = 0;
        for (char c: s){
            if (c == 'A') x = 2 * x + y;
            if (c == 'B') y = 2 * y + x;
        }
        return x + y;
    }
};