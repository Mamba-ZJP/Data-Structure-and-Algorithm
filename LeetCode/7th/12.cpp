class Solution {
public:
    map<int,string> Map{
        {1,"I"},
        {4,"IV"},
        {5,"V"},
        {10,"X"},
        {50,"L"},
        {100,"C"},
        {500,"D"},
        {1000,"M"},
        {9,"IX"},
        {40,"XL"},
        {90,"XC"},
        {400,"CD"},
        {900,"CM"}
    };

    string intToRoman(int num) {
        string ans = "",s;
        for(auto pos = Map.rbegin(); pos != Map.rend(); ++pos){
            if(num <= 0) break;
            s = pos->second;
            int cur = pos->first;
            while(num >= cur){
                num -= cur; ans += s;
            }
        }
        return ans;
    }
};
