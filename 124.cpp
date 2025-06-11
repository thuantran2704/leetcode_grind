    class Solution {
public:
    int ans = INT_MIN;

    int dfs(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, dfs(root->left));
        int right = max(0, dfs(root->right));
        ans = max(ans, left + right + root->val);

        // return the best single path upward
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
