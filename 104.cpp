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
        int height = INT_MIN;
    
        void m(TreeNode* root, int h){
            if(!root){
                height = max(height,h-1);
                return;
            }
            m(root -> left, h+1);
            m(root -> right,h+1);
        }
        int maxDepth(TreeNode* root) {
            m(root, 1);
            return height;
        }
    };