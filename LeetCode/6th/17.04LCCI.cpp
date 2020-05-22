class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i <= n;++i) sum += i;
        for(int num:nums) sum -= num;
        return sum;
        // unordered_set<int> hash_set;
        // for(int i = 0;i <= n;++i) hash_set.insert(i);
        // for(int num:nums){
        //     hash_set.erase(num);
        // }
        // return *hash_set.begin();
    }
};
