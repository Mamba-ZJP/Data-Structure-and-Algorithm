class Solution {
public:
    vector<string> ans = {};
    vector<vector<char>> tele = {
        {'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},
        {'m','n','o'},{'p','q','r','s'},{'t','u','v'},
        {'w','x','y','z'}
    };
    string digits;
    int n;
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(!n) return {};
        this->digits = digits;
        string cur(n,' ');
        dfs(0,cur);
        return ans;
    }

    void dfs(int depth,string& cur){
        if(depth == n){
            ans.push_back(cur); return;
        }
        int pos = digits[depth] - '2';
        for(int i = 0;i < tele[pos].size();++i){
            cur[depth] = tele[pos][i];
            dfs(depth + 1,cur);
        }
    }

};
