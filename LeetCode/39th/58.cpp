class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length();
        if (!n) return 0;
        string last = "";
        for (int i = 0; i < n; ) {
            while (i < n && s[i] == ' ') i++;

            if (i < n) last = "";

            while (i < n && s[i] != ' ') last += s[i++];
        }

        return last.length();
    }
};