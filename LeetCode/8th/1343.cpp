class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int i = 0, n = arr.size(), j = i + k;
        //[i,j)
        int sum = 0;
        for(int k = i; k < j; ++k) sum += arr[k];
        
        int ans = (sum / k >= threshold) ? 1 : 0;
        while(j < n){
            sum -= arr[i++];
            sum += arr[j++];
            if(sum / k >= threshold) ans++;
        }
        return ans;
    }
};
