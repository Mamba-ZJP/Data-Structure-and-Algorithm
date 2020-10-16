#define pub push_back
#define tos to_string

// 也可以自己重新写排序
class Solution {
private:
    string ans;
    static bool cmp(string &lhs, string &rhs) {
        string s1 = lhs + rhs;
        string s2 = rhs + lhs;
        return s1 > s2;
    }
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for (const int &el: nums) a.pub(tos(el));
        sort(a.begin(), a.end(), cmp);
        for (const auto &s: a) ans += s;
        if (ans[0] == '0') return "0";
        return ans;
    }
};