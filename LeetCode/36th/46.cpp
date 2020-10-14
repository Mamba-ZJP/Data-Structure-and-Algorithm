#define pub push_back
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums, vis, cur;
    int n;
    void dfs(int idx) {
        if (idx == n) {
            ans.pub(cur);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            vis[i] = 1;
            cur[idx] = nums[i];
            dfs(idx + 1);
            vis[i] = 0;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        this->nums = nums, n = nums.size();
        vis.resize(n + 1, 0);
        cur.resize(n, 0);
        dfs(0);
        return ans;
    }
};