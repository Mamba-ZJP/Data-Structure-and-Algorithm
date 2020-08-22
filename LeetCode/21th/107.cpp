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
    vector<vector<int>> ans;
public:
    vector<vector<int>> levelOrderBottom(TreeNode* rt) {
        queue<TreeNode *> Q;
        Q.push(rt);
        vector<int> t;
        while (Q.size()){
            int s = Q.size();
            t.clear();
            while (s--){
                auto cur = Q.front(); Q.pop();
                if (cur == NULL) continue;
                t.push_back(cur->val);
                Q.push(cur->left);
                Q.push(cur->right);
            }
            if (t.size()) ans.push_back(t);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
