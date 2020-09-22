#include <vector>
using namespace std;
class NumArray {
private:
    vector<int> pre;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        pre.resize(n + 1);
        pre[0] = 0;
        for (int i = 1; i <= n; i++) 
            pre[i] = pre[i - 1] + nums[i - 1];
    }
    
    int sumRange(int i, int j) {
        return pre[j + 1] - pre[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */