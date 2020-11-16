class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        n = pos.size(), this->m = m, this->pos = pos;
        sort(pos.begin(), pos.end());
        int l = 1, r = pos[n - 1];
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (check(mid, pos)) l = mid;
            else r = mid - 1;
        }
        return r;
    }
private:
    int n, m;
    vector<int> pos;
    inline bool check(int d, const vector<int> &pos) {
        int pre = pos[0], k = m - 1;
        for (int i = 1; i < n; i++) {
            if (pos[i] - pre >= d) k--, pre = pos[i];
            if (k == 0) return true;
        }
        return k <= 0;
    }
};