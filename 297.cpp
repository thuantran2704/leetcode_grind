class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        deque<TreeNode*> cur;
        cur.push_back(root);
        while(!cur.empty()){
            TreeNode* temp = cur.front();
            cur.pop_front();
            if(temp == nullptr){
                ans += "null#";
                continue;
            }
            ans+=to_string(temp -> val) + "#";
            cur.push_back(temp -> left);
            cur.push_back(temp -> right);
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n = data.size();
        string cur = "";
        deque<TreeNode*> parent;
        int i = 0;
        while(i < n && data[i]!= '#'){
            cur += data[i];
            i++;
        }
        i++;// pass this.
        TreeNode* par = nullptr;
        if(cur == "null") return nullptr;
        TreeNode* top = new TreeNode(stoi(cur));
        parent.push_back(top);
        //find top
        cur = "";
        while(i < n){
            if(data[i] != '#') cur += data[i];
            else {
                TreeNode* temp = nullptr;
                if(cur != "null"){
                    temp = new TreeNode(stoi(cur));
                    parent.push_back(temp);
                }
                if(par != nullptr){
                    par -> right = temp;
                    par = nullptr;
                } else {
                    par = parent.front();
                    parent.pop_front();
                    par -> left = temp;
                }
                
                cur = "";
            }
            i++;
        }
        return top;
    }
};