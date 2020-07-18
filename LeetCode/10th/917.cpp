class Solution {
public:
    inline bool isLetter(const char & c){
        if(c >= 'a' && c <= 'z') return true;
        if(c >= 'A' && c <= 'Z') return true;
        return false;
    }
    string reverseOnlyLetters(string S) {
        //双指针
        int i = 0, j = S.size() - 1;
        while(i < j){
            while(i < j && !isLetter(S[i])) ++i;
            while(i < j && !isLetter(S[j])) --j;

            swap(S[i++], S[j--]);
        }

        return S;
    }
};
