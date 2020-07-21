/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorder;
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* ans = new TreeNode(0);
        TreeNode* t = ans;
        for(int & node : inorder){
            t->right = new TreeNode(node);
            t = t->right;
        }
        return ans->right;
    }

    void dfs(TreeNode* rt){
        if(rt == NULL) return;
        dfs(rt->left);
        inorder.push_back(rt->val);
        dfs(rt->right);
    }
};
