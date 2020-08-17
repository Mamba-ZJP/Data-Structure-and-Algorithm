class Solution {
private:
    unordered_map<char, char> Map = {
        {')', '('}, {']', '['}, {'}', '{'}
    };
public:
    bool isValid(string s) {
        if (s.empty()) return true;
        stack<char> S;
        int n = s.length();
        for (int i = 0; i < n; ++i){
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') S.push(c);
            else {
                if (S.empty() || S.top() != Map[c]) return false;
                else S.pop();
            }
        }
        return S.empty();
    }
};
