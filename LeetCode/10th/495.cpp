class Solution {
public:
    int findPoisonedDuration(vector<int>& time, int duration) {
        if(time.empty()) return 0;
        //1e4
        int lim = 0, ans = 0;
        for(int i = 1, n = time.size(); i < n; ++i){
            ans += (min(time[i] - time[i - 1], duration));
        }
        return ans + duration;
    }
};
