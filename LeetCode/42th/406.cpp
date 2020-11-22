class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& peo) {
        sort(peo.begin(), peo.end(), cmp);
        int n = peo.size();
        ans.resize(n); vis.resize(n);
        int i, j, k;
        for (i = 0; i < n; i++) {
            for (j = 0, k = 0; j < n; j++) {
                if (!vis[j]) k++;
                if (k > peo[i][1]) break;
            }
            vis[j] = 1, ans[j] = peo[i];
        }

        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> vis;
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
};