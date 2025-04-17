class Solution {
    public:
        vector<int> parent;
        
        int find(int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(int x, int y) {
            int xp = find(x);
            int yp = find(y);
            if (xp != yp) parent[xp] = yp;
        }
    
        bool isBipartite(vector<vector<int>>& graph) {
            int n = graph.size();
            parent.resize(n);
            for (int i = 0; i < n; ++i) parent[i] = i;
    
            for (int u = 0; u < n; ++u) {
                for (int v : graph[u]) {
                    // If u and v are in the same set, not bipartite
                    if (find(u) == find(v)) return false;
    
                    // Union the neighbors of u into the same group
                    // Use graph[u][0] as a representative group
                    if (!graph[u].empty()) {
                        unite(graph[u][0], v);
                    }
                }
            }
            return true;
        }
    };