class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i;
        int L = 0, R = n - 1;
        //range [L, R]， 所以特判下缺失的是最后一个数
        if (!nums.size() || nums.back() == n - 1) return n; 
        while (L < R){
            int M = (L + R) >> 1;
            if (nums[M] > M) R = M;
            else L = M + 1;
          
        }
        //返回nums[i] > i的第一个数的下标
        return L;

        // for (i = 0; i < n; ++i)
        //     if (nums[i] != i) break;
        // return i;
    }
};
