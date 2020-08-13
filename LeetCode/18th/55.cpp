class Solution {
public:
    bool canJump(vector<int>& nums) {
        // 3e4
        int maxd = 0, n = nums.size();
        for (int i = 0; i < n; ++i){
            maxd = max(maxd, i + nums[i]);
            if (maxd >= n - 1) return true;
            if (maxd <= i) return false;
        }
        return true;
    }
};
