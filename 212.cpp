class Solution {
public:

    class Node {
public:
    char c;
    Node* next[26];
    bool end;
    string the_word;
    Node(char cur){
        c = cur;
        end = false;
        for(int i = 0; i < 26; i++) next[i] = nullptr;  // initialize pointers to nullptr
    }
};


class Trie {
public:
    Node* root;
    Trie(){
        root = new Node('#');
    }
    void insert(string word){
        int k = word.size();
        Node* cur = root;
        for(int i = 0; i < k; i++){
            int idx = word[i] - 'a';
            if(cur->next[idx] == nullptr) cur->next[idx] = new Node(word[i]);
            cur = cur->next[idx];
        }
        cur->end = true;
        cur->the_word = word;
    }
    bool avail(Node* cur, char c){
        return cur->next[c - 'a'] != nullptr;
    }
};

void dfs(vector<vector<char>>& board, int i, int j, Node* cur, Trie& trie){
    if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '#' || !trie.avail(cur, board[i][j])) return;
    // your existing dfs logic
    
    char c = board[i][j];
    Node* no = cur -> next[c-'a'];
    if(no == nullptr) return;
    if(no-> end){
        ans.push_back(no -> the_word);
        no -> end = false;
    }
    board[i][j] = '#';
    dfs(board,i+1, j, no, trie);
    dfs(board,i-1, j, no, trie);
    dfs(board,i, j+1, no, trie);
    dfs(board,i, j-1, no, trie);
    board[i][j] = c;
}
vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie = Trie();  // prefer this style over `Trie trie = new Trie();`
        for(const string& word: words){
            trie.insert(word);
        }
        int n = board.size();
        int m = board[0].size();
        Node* root = trie.root;
        for(int i = 0 ; i < n; i++){
            for(int j = 0; j < m; j++){
                if(trie.avail(root, board[i][j])) dfs(board, i, j, root, trie);
            }
        }
        return ans;
    }
};