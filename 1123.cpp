class Solution {
    public:
        pair<int, TreeNode*> helper(TreeNode* root) {
            if (!root) return {0, nullptr}; // Base case: null node has depth 0
    
            auto left = helper(root->left);
            auto right = helper(root->right);
    
            int left_depth = left.first, right_depth = right.first;
    
            if (left_depth == right_depth) {
                return {left_depth + 1, root}; // If equal depth, current node is LCA
            } else if (left_depth > right_depth) {
                return {left_depth + 1, left.second}; // Return deeper subtree's LCA
            } else {
                return {right_depth + 1, right.second}; // Return deeper subtree's LCA
            }
        }
    
        TreeNode* lcaDeepestLeaves(TreeNode* root) {
            return helper(root).second; // Get LCA from helper
        }
    };
    