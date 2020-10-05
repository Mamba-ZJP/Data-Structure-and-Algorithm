#include <queue>
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
    queue<TreeNode *> Q;
public:
    bool isEvenOddTree(TreeNode* rt) {
        Q.push(rt);
        int lev = 0;
        while (Q.size()) {
            int s = Q.size();
            int pre = (lev % 2) ? 2e9 : -1;
            
            while (s-- > 0) {
                auto c = Q.front(); Q.pop();
                if (lev % 2) { //奇数层
                    if (c->val % 2 != 0 || c->val >= pre) return false; 
                    pre = c->val;
                }
                else { // 偶数层
                    if (c->val % 2 != 1 || c->val <= pre) return false;
                    pre = c->val;
                }
                if (c->left) Q.push(c->left);
                if (c->right) Q.push(c->right);
            }
            
            lev++;
        }
        return true;
    }
};