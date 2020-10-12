#define pub push_back
// 法1：暴力枚举
class Solution {
private:
    int count(int x) {
        int cnt = 0;
        while (x) {
            if (x & 1) cnt++;
            x >>= 1;
        }
        return cnt;
    }
    vector<string> ans;
public:
    vector<string> readBinaryWatch(int num) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (count(i) + count(j) == num)
                    ans.pub(to_string(i) + ":" + (j < 10 ? "0" + to_string(j) : to_string(j)));
            }
        }
        return ans;
    }
};

// 法2：回溯
#define pub push_back
#define tos to_string
class Solution {
private:
    vector<string> ans;
    void dfs1(int i, int dep, vector<int> &hour, int cur) {
        if (i == 0) {
            if (cur >= 0 && cur <= 11) hour.pub(cur);
            return;
        }
        if (dep > 3) return;
        dfs1(i - 1, dep + 1, hour, cur + pow(2, dep));
        dfs1(i, dep + 1, hour, cur);
    }

    void dfs2(int j, int dep, vector<int> &min, int cur) {
        if (j == 0) {
            if (cur >= 0 && cur <= 59) min.pub(cur);
            return;
        }
        if (dep > 6) return;
        dfs2(j - 1, dep + 1, min, cur + pow(2, dep));
        dfs2(j, dep + 1, min, cur);
    }
public:
    vector<string> readBinaryWatch(int num) {
        // 上面最多4个
        for (int i = 0; i <= min(num, 3); i++) {
            int j = num - i;
            if (j > 5) continue;
            vector<int> hour, min;
            dfs1(i, 0, hour, 0);
            dfs2(j, 0, min, 0);
            string t;
            if (min.size() && hour.size()) {
                for (int &h: hour) {
                    for (int &m: min) {
                        t = tos(h) + ":" + (m < 10 ? "0" + tos(m) : tos(m));
                        ans.pub(t);
                    }
                }
            } else if (min.empty()) {
                for (int &h: hour) {
                    t = tos(h) + ":00";
                    ans.pub(t);
                }
            } else if (hour.empty()) {
                for (int &m: min) {
                    t = "0:" + (m < 10 ? "0" + tos(m) : tos(m));
                    ans.pub(t);
                }
            } else {
                ans.pub("0:00");
            }
        }
        return ans;

    }
};