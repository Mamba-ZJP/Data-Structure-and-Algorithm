class Solution {
public:
    string predictPartyVictory(string senate) {
       //1e4//模拟 每个点只会遍历一次
        memset(st, 0, sizeof st);
        int n = senate.size();
        int ban[2] = {0, 0};
        int race[2] = {0, 0};

        queue<char> Q;
        int r = 0, d = 0;
        for (const auto & c :senate){
            Q.push(c == 'R' ? 0 : 1);
            if (c == 'R') race[0]++;
            else race[1]++;
        }

        while (race[1] > 0 && race[0] > 0){
            int cur = Q.front(); Q.pop();
            
            if (ban[cur] > 0){
                ban[cur]--;
                race[cur]--;
            }
            else {
                Q.push(cur);
                ban[cur ^ 1]++;
            }
        }

        if (race[0] > 0) return "Radiant";
        return "Dire";
    }
};
