class Solution {
private:
    int N;
    int vis[16];
    void dfs(int idx) {
        if (idx > N) {
            ans++; return;
        }
        for (int i = 1; i <= N; i++) {
            if (vis[i]) continue;
            if (idx % i == 0 || i % idx == 0) {
                vis[i] = 1;
                dfs(idx + 1);
                vis[i] = 0;
            }
        }
    }
public:
    int countArrangement(int N) {
        this->N = N, ans = 0;
        dfs(1);
        return ans;
    }
};