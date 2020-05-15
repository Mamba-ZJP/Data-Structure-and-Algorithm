class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int R = nums.size();
        int L = 0;
        while(L < R){
            int M = (L + R) / 2;
            if(nums[M] == target) return M;
            else if(nums[M] > target) R = M;
            else L = M + 1;
        }
        return L;
    }
};
