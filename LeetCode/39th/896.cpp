class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int n = A.size();
        if (n == 1) return true;
        int isIncrease = -1;
        
        for (int i = 1; i < n; i++) {
            if (A[i] == A[i - 1]) continue;
            if (isIncrease == -1) {
                if (A[i] > A[i - 1]) isIncrease = 1;
                else isIncrease = 0;
            } else {
                if (isIncrease && A[i] < A[i - 1]) return false;
                if (!isIncrease && A[i] > A[i - 1]) return false;
            }
        }

        return true;
    }
};