// O(n)
// 1.hash 2.sort
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        n /= 2;
        int major, cnt = 0;
        for (int a: nums) {
            if (!cnt) major = a, cnt++;
            else {
                if (major != a) cnt--;
                else cnt++;
            }
        }

        // major 不一定是出现了 > (n / 2) 次
        if (cnt) {
            cnt = 0;
            for (int a: nums) if (a == major) cnt++;
            if (cnt > n) return major;
        }
        return -1;
    }
};