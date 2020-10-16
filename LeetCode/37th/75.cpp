class Solution {
public:
    void sortColors(vector<int>& nums) {
        // red 0 white 1 blue 2
        int n = nums.size();
        int zero = 0, two = n - 1, i = 0;
        while (i <= two) {
            if (nums[i] == 1) i++;
            else if (nums[i] == 0) { // 和zero边界值交换必定是1
                swap(nums[zero], nums[i]); 
                zero++, i++;
            }
            else {
                swap(nums[two], nums[i]); 
                two--;
            }
        }
    }
};