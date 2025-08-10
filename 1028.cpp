class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            int n = traversal.size();
            stack<pair<TreeNode*, int>> st;  // pair of node and depth
            int i = 0;
    
            while (i < n) {
                int depth = 0;
                while (i < n && traversal[i] == '-') {
                    depth++;
                    i++;
                }
    
                string cur = "";
                while (i < n && isdigit(traversal[i])) {
                    cur += traversal[i++];
                }
    
                TreeNode* node = new TreeNode(stoi(cur));
    
                while (!st.empty() && st.top().second >= depth) {
                    st.pop();
                }
    
                if (!st.empty()) {
                    TreeNode* parent = st.top().first;
                    if (parent->left == nullptr)
                        parent->left = node;
                    else
                        parent->right = node;
                }
    
                st.push({node, depth});
            }
    
            // The bottom of the stack is the root
            while (st.size() > 1) st.pop();
            return st.top().first;
        }
    };