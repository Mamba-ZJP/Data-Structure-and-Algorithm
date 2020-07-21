/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//TC:O(n) MC:O(n)
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

//TC:O(n) MC:O(1)

class Solution {
public:
    TreeNode * fa;
    TreeNode* increasingBST(TreeNode* root) {
        fa = new TreeNode{};
        TreeNode* ans = fa;
        dfs(root);
        return ans->right;
    }

    void dfs(TreeNode* rt){
        if(!rt) return;
        dfs(rt->left);
        rt->left = NULL;
        fa->right = rt;
        fa = rt;
        dfs(rt->right);
    }
};
