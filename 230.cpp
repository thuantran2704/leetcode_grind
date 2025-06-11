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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> cur;
        TreeNode* temp = root;
        int count = 0;
        while(true){
            while(temp!= nullptr){
                cur.push(temp);
                temp = temp -> left;
            }
            TreeNode* top = cur.top();
            cur.pop();
            count++;
            if(count == k) return top -> val;
            if(top -> right != nullptr) temp = top -> right;
        }
        return -1;
    }
};