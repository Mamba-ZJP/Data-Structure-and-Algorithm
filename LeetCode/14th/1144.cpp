class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        //暴力:
        //even：第一种情况 直接判断奇数索引和相邻的最小偶数索引差是多少
        int n = nums.size(), i = 1, sum = 0;
        while (i < n){
            int left = nums[i - 1];
            int right = (i == n - 1 ? INT_MAX : nums[i + 1]);
            int t = nums[i] - min(left, right);
            sum += (t < 0 ? 0 : abs(t) + 1);
            i += 2;
        }
        //odd
        i = 0;
        int ret = 0;
        while (i < n){
            int left = (i == 0 ? INT_MAX : nums[i - 1]);
            int right = (i == n - 1 ? INT_MAX : nums[i + 1]);
            int t = nums[i] - min(left, right);
            ret += (t < 0 ? 0 : abs(t) + 1);
            i += 2;
        }
        return min(ret, sum);
    }
};
