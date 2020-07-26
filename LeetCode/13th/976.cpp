class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        //1e4
        //perimeter max  area != 0
        //a + b > c  f() = a + b + c
        sort(A.begin(), A.end());
        //从大到小枚举一个边长，那么另外两个边长就枚举比它小的两个
        //如果没法满足a+b>c，那么最长的边长任何一种情况都不会满足了
        for(int i = A.size() - 1; i >= 2; --i){
            if(A[i] < A[i - 1] + A[i - 2])
                return A[i] + A[i - 1] + A[i - 2];
        }
        return 0;
    }
};
