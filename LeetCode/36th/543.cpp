class Solution {
private:
    int ans;
    int dfs(TreeNode * rt) {
        if (!rt) return -1;
        int l = dfs(rt->left) + 1, r = dfs(rt->right) + 1;
        ans = max(ans, l + r);
        return max(l, r);
    }
public:
    int diameterOfBinaryTree(TreeNode* rt) {
        ans = 0;
        dfs(rt);
        return ans;
    }
};