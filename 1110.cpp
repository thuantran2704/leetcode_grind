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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> s (to_delete.begin(),to_delete.end());
        deque<pair<TreeNode*,TreeNode*>> cur;
        cur.push_back({nullptr,root});
        while(!cur.empty()){
            TreeNode* temp = cur.front().second;
            TreeNode* prev = cur.front().first;
            cur.pop_front();
            if(temp == nullptr) continue;
            TreeNode* l = temp -> left;
            TreeNode* r = temp -> right;
            if(s.count(temp -> val)){
                if(prev != nullptr){
                    if(prev -> left == temp){
                        prev -> left = nullptr;
                    } else {
                        prev -> right = nullptr;
                    }
                }
                temp = nullptr;
            }
            if(prev == nullptr && temp != nullptr ) ans.push_back(temp);

            cur.push_back({temp, l});
            cur.push_back({temp, r});
        }
        return ans;
    }
};