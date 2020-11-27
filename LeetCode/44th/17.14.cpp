class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        this->k = k, n = arr.size();
        quickSort(arr, 0, n - 1);
        return vector<int>(arr.begin(), arr.begin() + k);
    }
private:
    int k, n;
    void quickSort(vector<int> &A, int l, int r) {
        if (l >= r) return;

        int left = l + 1, right = r, pvt = A[l];
        while (left <= right) {
            while (left <= right && A[left] <= pvt) left++;
            while (left <= right && A[right] >= pvt) right--;

            if (left > right) break;
            swap(A[left++], A[right--]);
        }
        swap(A[l], A[left - 1]);

        if (right == k - 1) return;
        if (k - 1 > left - 1) quickSort(A, right + 1, r);
        else quickSort(A, l, right - 1);
    }
};