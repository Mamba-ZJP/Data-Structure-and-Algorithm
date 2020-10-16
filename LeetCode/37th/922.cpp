class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int n = A.size();
        vector<int> ans(n);
        int oddIdx = 1, evenIdx = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] % 2) ans[oddIdx] = A[i], oddIdx += 2;
            else ans[evenIdx] = A[i], evenIdx += 2;
        }
        return ans;
    }
};