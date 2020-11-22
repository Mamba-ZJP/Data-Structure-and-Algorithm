class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sta = 0, n = gas.size(), left = gas[0];

        for (int i = 0; i < 2 * n; i++) {
            left -= cost[i % n];
            if (left < 0) sta = i + 1, left = gas[(i + 1) % n];
            else left += gas[(i + 1) % n];

            if (sta > n - 1) return -1;
        }
        
        return sta;
    }
};