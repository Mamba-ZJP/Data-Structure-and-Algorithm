#include <iostream>
#include <vector>

#define pub push_back
#define pob pop_back
using namespace std;
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> nums, used;
    int n;
    void dfs(int idx) {
        if (idx == n) {
            vector<int> t;
            for (int i = 0; i < n; i++) 
                if (used[i]) t.pub(nums[i]);
            ans.pub(t);
            return;
        }

        used[idx] = 0;
        dfs(idx + 1);
        used[idx] = 1;
        dfs(idx + 1);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums, n = nums.size();
        used.resize(n, 0);
        dfs(0);
        return ans;
    }
};