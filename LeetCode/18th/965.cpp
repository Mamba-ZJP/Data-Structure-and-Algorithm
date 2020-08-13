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
private:
    int c = -1;
public:
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        if (c != -1 && root->val != c) return false;
        else c = root->val;
        return isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};
