class Solution {
public:
    int trans(const char&c){
        if(c == 'I') return 1;
        if(c == 'V') return 5;
        if(c == 'X') return 10;
        if(c == 'L') return 50;
        if(c == 'C') return 100;
        if(c == 'D') return 500;
        if(c == 'M') return 1000;
        return 1;
    }
    
    bool Judge(const char& cur,const char& next){
        if(cur == 'I' && (next == 'V' || next == 'X')) 
            return true;
        if(cur == 'X' && (next == 'L' || next == 'C'))
            return true;
        if(cur == 'C' && (next == 'D' || next == 'M'))
            return true;

        return false;
    }

    int romanToInt(string s) {
        int ans = 0, n = s.size();
        for(int i = 0; i < n; ++i){
            char cur = s[i];
            int curNum = trans(cur);

            if(i + 1 >= n){
                ans += curNum; continue;
            } 

            char next = s[i + 1];
            int nextNum = trans(next);
            
            if(Judge(cur,next)){
                ans += (nextNum - curNum);
                ++i;
            }
            else ans += curNum;
        }

        return ans;
    }
};
