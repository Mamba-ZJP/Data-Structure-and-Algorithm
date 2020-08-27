class Solution {
public:
    string getHint(string secret, string guess) {
        // length equal
        int A = 0, B = 0;
        int n = secret.length();
        unordered_map<char, int> rec;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; ++i){
            if (secret[i] == guess[i]) A++, vis[i] = 1;
            else rec[secret[i]]++;
        }
        
        for (int i = 0; i < n; ++i){
            if (vis[i]) continue;
            if (rec.count(guess[i])){
                if (rec[guess[i]] > 0) rec[guess[i]]--, B++;
                else rec.erase(guess[i]);
            }
        }

        string ans = to_string(A) + 'A' + to_string(B) + 'B';
        return ans;
    }
};
