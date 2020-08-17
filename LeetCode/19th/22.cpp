class Solution {
private:
    int n;
    vector<string> ans;
    void dfs(int lB, int rB, string & s, int idx){
        if (lB == n && rB == n) {
            ans.push_back(s); return;
        }
        if (lB < n) {
            s[idx] = '(';
            dfs(lB + 1, rB, s, idx + 1);
        }
        if (lB > rB){
            s[idx] = ')';
            dfs(lB, rB + 1, s, idx + 1);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        this->n = n;
        string s(2 * n, ' ');
        dfs(0, 0, s, 0);
        return ans;
    }
};
