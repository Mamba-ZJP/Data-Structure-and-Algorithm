class Solution {
public:
    // n -> [1, n - 1]
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) return nums[i];
        }
        return 1;
    }
};