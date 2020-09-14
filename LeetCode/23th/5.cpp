class Solution {
public:
    string longestPalindrome(string s) {
        string ans;
        int n = s.size();
        if(n < 2) return s;
        vector<vector<int>> dp(n,vector<int>(n,1));
        int maxlen = 1,pos = 0;
        for(int i = n - 2;i >= 0;--i){
            for(int j = n - 1;j > i;--j){
    //dp(i+1,j-1) -> dp(i,j) //递推顺序至关重要
                if(s[i] != s[j]) dp[i][j] = 0;
                else{
                //如果说这只是个小于等于三个字符的子串
                    if(j - i + 1 <= 3) dp[i][j] = 1;
                    else dp[i][j] = dp[i + 1][j - 1];
                }

                 //能够成回文串，更新maxlength，更新postion
                if(dp[i][j] && j - i + 1 > maxlen){
                    maxlen = j - i + 1; pos = i;
                }
            }

        }

        return s.substr(pos,maxlen);
    }
};
