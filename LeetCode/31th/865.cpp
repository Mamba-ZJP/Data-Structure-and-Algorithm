#include <unordered_map>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    unordered_map<TreeNode *, int> dep;
    TreeNode * ans;
    // 记录每个根节点的叶子结点的深度（根节点的高度）。
    // 方便之后查询左右结点的深度
    int recordDepth(TreeNode * rt) {
        if (!rt) return -1;
        dep[rt] = max(recordDepth(rt->left), 
                      recordDepth(rt->right)) + 1;
        return dep[rt]; 
    }
    // 自顶向下 找到了就可以返回了
    void dfs(TreeNode * rt) {
        if (!rt) return;
        if (rt->left && rt->right){
            if (dep[rt->left] > dep[rt->right]) 
                dfs(rt->left);
            else if (dep[rt->left] < dep[rt->right]) 
                dfs(rt->right);
            else 
                ans = rt;
        }
        else if (rt->left) dfs(rt->left);
        else if (rt->right) dfs(rt->right);
        else ans = rt;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* rt) {
        recordDepth(rt);
        dfs(rt);
        return ans;
    }
};