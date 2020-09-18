class Solution {
public:
    vector<vector<int>> ans;
    int n,k;
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        dfs(1,0,{});
        return ans;
    }

    void dfs(int begin,int depth,vector<int> cur){
        if(depth == k){
            ans.push_back(cur); return;
        }
        if(begin > n) return;

        for(int i = begin;i <= n;++i){
            if(n - i + 1 < k - cur.size()) break;
            cur.push_back(i);
            dfs(i + 1,depth + 1,cur);
            cur.pop_back();
        }
    }
};
