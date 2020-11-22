class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i, j, n = g.size(), m = s.size(), ans = 0;
        for (i = 0, j = 0; j < n && i < m; i++) {
            if (s[i] >= g[j]) ans++, j++;
        }
        
        return ans;
    }
};