#define pub push_back
class Solution {
private:
    vector<int> ans;
    int pre, cnt, maxCnt;
    void update(int v) {
        if (v == pre) cnt++;
        else pre = v, cnt = 1;

        if (cnt > maxCnt) 
            maxCnt = cnt, ans = {v};
        else if (cnt == maxCnt) 
            ans.pub(v);
        
    }
    void dfs(TreeNode * rt) {
        if (!rt) return;
        dfs(rt->left);
        update(rt->val);
        dfs(rt->right);
    }
public:
    vector<int> findMode(TreeNode* rt) {
        ans = {}, pre = INT_MAX, cnt = maxCnt = 0;
        dfs(rt);
        return ans;
    }
};