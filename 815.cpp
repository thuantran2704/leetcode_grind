class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
            int n = routes.size();
            if(source == target) return 0;
            unordered_set<int> visitedR;
            unordered_map<int, unordered_set<int>> stations;
            unordered_set<int> goalRoutes;
            //stations abc has routes xyz?
            for(int i = 0 ; i < n;i++){
                for(auto& stop: routes[i]){
                    stations[stop].insert(i);
                    if(stop == target) goalRoutes.insert(i);
                }
            }
            unordered_set<int> visitedstops;
            visitedstops.insert(source);
            int count = 0;
            queue<int> qu;
            qu.push(source);
            while(!qu.empty()){
                int k = qu.size();
                count++;
                for(int idx = 0 ; idx < k;idx++){
                    int cur = qu.front();
                    qu.pop();
                    for(auto& route: stations[cur]){
                        if(visitedR.count(route)) continue;
                        visitedR.insert(route);
                        if(goalRoutes.count(route)) return count;
                        else {
                            for(auto& stops: routes[route]){
                                if(visitedstops.count(stops)) continue;
                                qu.push(stops);
                                visitedstops.insert(stops);
                            }
                        }
                    }
                }
    
            }
            return -1;
        }
    };