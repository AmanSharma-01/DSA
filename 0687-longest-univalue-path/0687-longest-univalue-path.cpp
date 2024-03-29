/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    int dfs(TreeNode* root, int& ans) {
        if(!root) return 0;
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        if(!root->left || root->left->val != root->val) l = 0;
        if(!root->right || root->right->val != root->val) r = 0;
        ans = max(ans, l+r);
        return max(l, r)+1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        if(!root) return 0;
        int maxPath=0;
        dfs(root, maxPath);
        return maxPath;
    }
};