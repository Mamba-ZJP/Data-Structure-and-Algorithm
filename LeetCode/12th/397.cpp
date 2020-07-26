class Solution {
public:
    unordered_map<int, int> hash_map;
    int half = ((long long)INT_MAX + 1) / 2;

    int integerReplacement(int n) {
        if(n == 1) return 0;
        if(hash_map.count(n)) return hash_map[n];
        int t;
        if(!(n % 2)) 
            t = integerReplacement(n / 2) + 1;
        else if(n == INT_MAX)
            t = min(integerReplacement(n - 1) + 1, integerReplacement(half) + 2);
        else
            t = min(integerReplacement(n - 1), integerReplacement(n + 1)) + 1;
        
        return hash_map[n] = t;
    }
};
