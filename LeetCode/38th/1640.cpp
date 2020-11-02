// st[]
int st[105];
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pie) {
        memset(st, 0, sizeof(st));
        int n = arr.size();
        unordered_map<int, int> idx;
        
        for (int i = 0; i < n; i++) idx[arr[i]] = i; 
        
        for (const auto &p: pie) {
            bool f = true;
            int preIdx = -1;
            for (int c: p) {
                if (preIdx == -1) preIdx = idx[c]; 
                else {
                    if (!idx.count(c)) {
                        f = false; break;
                    } else {
                        if (idx[c] != preIdx + 1) {
                            f = false; break;
                        } else preIdx++;
                    }
                }
            }
            
            if (f) for (int c: p) st[idx[c]] = 1;
         }
        
        bool ans = true;
        for (int i = 0; i < n; i++) if (!st[i]) ans = false;
        return ans;
    }
};