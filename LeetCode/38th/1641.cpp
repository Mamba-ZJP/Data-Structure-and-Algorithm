class Solution {
public:
    int n, ans;    
    void dfs(int dep, int c) {
        if (dep == n) {
            ans++; return;
        }
        for (int i = c; c <= 5; c++) 
            dfs(dep + 1, c);
    }
    
    int countVowelStrings(int n) {
        this->n = n, ans = 0;
        dfs(0, 1);
        return ans;
    }
};