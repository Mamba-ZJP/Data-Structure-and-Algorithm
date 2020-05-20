class Solution {
public:
    bool validPalindrome(string s) {
        int j = s.size() - 1,i = 0;
        while(i < j){
            if(s[i] != s[j])
                return judge(s,i,j - 1) || judge(s,i + 1,j);
            i++; j--;
        }
        return true;
    }

    bool judge(const string& s,int i,int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};
