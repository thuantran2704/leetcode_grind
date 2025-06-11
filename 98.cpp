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
public:
    bool isvalid(TreeNode* root, long mi, long ma){
        if(root == nullptr) return true;
        return (root -> val > mi && root -> val < ma && isvalid(root -> left, mi, root -> val) && isvalid(root -> right, root -> val, ma));
    }
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        return isvalid(root -> left, LONG_MIN, root -> val) && isvalid(root -> right,root -> val, LONG_MAX);
    }
};