class Solution {
public:
    int heightChecker(vector<int>& heights) {
        //100
        vector<int> t = heights;
        int ans = 0;
        sort(t.begin(),t.end());
        for(int i = 0, n = heights.size(); i < n; ++i){
            if(t[i] != heights[i]) ans++;
        }

        return ans;
    }
};
