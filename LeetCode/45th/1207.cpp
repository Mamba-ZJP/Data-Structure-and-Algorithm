int cnt[2005];
unordered_set<int> rec;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        memset(cnt, 0, sizeof(cnt));
        rec.clear();

        for (int c: arr) cnt[c + 1000]++;
        
        for (int i = 0; i < 2005; i++) {
            if (cnt[i]) {
                if (rec.count(cnt[i])) return false;
                rec.insert(cnt[i]);
            }
        }

        return true;
    }
};