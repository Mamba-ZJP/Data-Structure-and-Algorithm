class Solution {
private:
    int pre;
    bool ans, first;
    void dfs(TreeNode * rt) {
        if (!flag) return;
        if (!rt) return;
        dfs(rt->left);
        if (first || rt->val > pre) 
            first = false, pre = rt->val;
        else ans = false;
        pre = rt->val;
        dfs(rt->right);
    }
public:
    bool isValidBST(TreeNode* rt) {
        ans = true, first = true;
        dfs(rt);
        return ans;
    }
};