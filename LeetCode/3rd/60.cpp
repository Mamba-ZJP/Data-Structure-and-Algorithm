class Solution {
public:
    int n,k;
    string ans;
    string getPermutation(int n, int k) {
        this->n = n; this->k = k;
        string cur(n,'0');
        int vis[n + 1];

        memset(vis,0,sizeof(vis));
        dfs(cur,0,vis);
        return ans;
    }
    int cnt = 0;
    
    void dfs(string& cur,int depth,int * vis){
        if(depth == n){
            cnt++; 
            if(cnt == k) ans = cur;
            return;
        }
        for(int i = 1;i <= n;++i){
            if(!vis[i]){
                vis[i] = 1;
                cur[depth] = ('0' + i);
                dfs(cur,depth + 1,vis);
                vis[i] = 0;
            }
        }
    }
};
