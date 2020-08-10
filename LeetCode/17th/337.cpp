/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 //树形dp
class Solution {
public:
    //每个rob返回当前结点能返回最大的值
    unordered_map<TreeNode *, int> Map;
    int rob(TreeNode* root) {
        if (!root) return 0;
        if (Map.find(root) != Map.end()) return Map[root];

        int sum = root->val;
        TreeNode * lc = root->left, * rc = root->right;
        int l = rob(lc), r = rob(rc);
        sum += (lc ? rob(lc->left) : 0);
        sum += (lc ? rob(lc->right) : 0);
        sum += (rc ? rob(rc->left) : 0);
        sum += (rc ? rob(rc->right) : 0);

        return Map[root] = max(sum, l + r);
    }
};
