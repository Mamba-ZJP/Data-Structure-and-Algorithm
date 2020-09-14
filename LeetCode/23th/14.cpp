class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 0) return "";
        string a = strs[0];
        int res = a.length();
        for (int i = 1; i < n; i++){
            string b = strs[i];
            int j, k = b.length();
            for (j = 0; j < min(b.length(), a.length()); j++)
                if (b[j] != a[j]) break;
            
            res = min(res, j);
        }
        return a.substr(0, res);
    }
};
