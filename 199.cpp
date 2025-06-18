class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<pair<TreeNode*,int>> levels;
        vector<int> ans;
        levels.push({root, 0});
        while(!levels.empty()){
            pair<TreeNode*,int> temp = levels.front();
            levels.pop();
            if(temp.first == nullptr) continue;
            if(ans.size() == temp.second) ans.push_back(0);
            ans[temp.second] =(temp.first -> val);
            levels.push({temp.first -> left, temp.second + 1});
            levels.push({temp.first -> right, temp.second + 1});
        }
        return ans;
    }
};