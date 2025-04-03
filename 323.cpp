class Solution {
    public:
        unordered_map<int,int> papi;
        int find(int i){
            while(i != papi[i]){
                papi[i] = papi[papi[i]];
                i = papi[i];
            }
            return i;
        }
        void unions(int p, int q){
            int x = find(p);
            int y = find(q);
            papi[x] = y;
        }
        int countComponents(int n, vector<vector<int>>& edges) {
            int m = edges.size();
            for(int i = 0; i < n;i++){
                papi[i] = i;
            }
            int count = 0;
            for(int i = 0; i < m;i++){
                int x = find(edges[i][0]);
                int y = find(edges[i][1]);
                if(x != y){
                    unions(edges[i][0],edges[i][1]);
                    count++;
                }
            }
            return n - count;
        }
    };