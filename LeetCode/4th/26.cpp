class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(!n) return 0;
        int i = 0;
        for(int j = 0;j < n;++j){
            if(nums[j] != nums[i]){
                ++i; nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
