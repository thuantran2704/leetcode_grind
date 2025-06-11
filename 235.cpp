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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return root;
        int mi = min(p -> val, q -> val);
        int ma = max(p -> val, q -> val);
        if(mi < root -> val && ma > root -> val || p == root || q == root) return root;
        else if(ma < root -> val) return lowestCommonAncestor(root -> left, p, q);
        else return lowestCommonAncestor(root -> right,p,q);
    }
};