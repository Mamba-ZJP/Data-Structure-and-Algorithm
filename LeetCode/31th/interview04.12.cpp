#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
private:
    int dfs(TreeNode * rt, int &sum, int cur) {
        int res = 0;
        if (!rt) return 0;
        cur += rt->val;
        if (cur == sum) res++;
        return res + dfs(rt->left, sum, cur) 
                   + dfs(rt->right, sum, cur);
    }
public:
    int pathSum(TreeNode* rt, int sum) {
        if (!rt) return 0;
        int res = dfs(rt, sum, 0);
        return res + pathSum(rt->left, sum) + pathSum(rt->right, sum);
    }
};