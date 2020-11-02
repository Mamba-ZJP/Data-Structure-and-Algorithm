#define pub push_back
class Solution {
private:
    vector<int> dist, h;
    int br, lad, ans, n;
    void dfs(int c, int br, int lad) {
        if (ans == n - 1) return;
        if (c == n - 1) {
            ans = max(ans, c); return;
        }
        
        int d = h[c + 1] - h[c];
        if (d <= 0) dfs(c + 1, br, lad);
        else {
            if (lad == 0 && br < d) {
                ans = max(ans, c); return;
            }
            if (lad > 0) dfs(c + 1, br, lad - 1);
            if (br >= d) dfs(c + 1, br - d, lad);
        }
    }
public:
    int furthestBuilding(vector<int>& h, int br, int lad) {
        int n = h.size();
        if (n == 1) return 0;
        this->br = br, this->lad = lad, this->h = h, ans = 0, this->n = n;
        dfs(0, br, lad);
        
        return ans;
        
    }
};