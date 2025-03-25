#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <iostream>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Build the adjacency list; note: iterate over roads, not n.
        unordered_map<int, vector<pair<int,int>>> adj;
        int m = roads.size();
        for (int i = 0; i < m; i++) {
            int u = roads[i][0], v = roads[i][1], w = roads[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        
        const int MOD = 1e9 + 7;
        // distances[i] will hold the minimum distance from node 0 to node i.
        vector<long long> dist(n, LLONG_MAX);
        // ways[i] will hold the number of shortest paths to node i.
        vector<int> ways(n, 0);
        
        // Use a priority queue to perform Dijkstra's algorithm.
        // Each element is {current_distance, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Initialization
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();
            
            // If we already found a better path before.
            if (d > dist[node]) continue;
            
            // Explore neighbors.
            for (auto &edge : adj[node]) {
                int neighbor = edge.first;
                int weight = edge.second;
                long long newDist = d + weight;
                
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    ways[neighbor] = ways[node];
                    pq.push({newDist, neighbor});
                } else if (newDist == dist[neighbor]) {
                    // Found an additional shortest path.
                    ways[neighbor] = (ways[neighbor] + ways[node]) % MOD;
                }
            }
        }
        
        // If destination is unreachable, ways[n-1] would be 0.
        return ways[n-1];
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<vector<int>> roads1 = {{0, 1, 1}, {1, 2, 1}, {0, 2, 2}};
    int n1 = 3;
    cout << "Test case 1 result: " << sol.countPaths(n1, roads1) << endl;  // Expected output: 2

    // Test case 2
    vector<vector<int>> roads2 = {{0, 1, 1}, {1, 2, 2}, {0, 2, 2}};
    int n2 = 3;
    cout << "Test case 2 result: " << sol.countPaths(n2, roads2) << endl;  // Expected output: 1

    // Test case 3
    vector<vector<int>> roads3 = {{0, 1, 5}, {1, 2, 5}, {0, 2, 10}};
    int n3 = 3;
    cout << "Test case 3 result: " << sol.countPaths(n3, roads3) << endl;  // Expected output: 1

    // Test case 4: Larger test case
    vector<vector<int>> roads4 = {{0, 1, 2}, {1, 2, 3}, {2, 3, 4}, {0, 3, 5}};
    int n4 = 4;
    cout << "Test case 4 result: " << sol.countPaths(n4, roads4) << endl;  // Expected output: 1

    // Test case 5: Unreachable destination
    vector<vector<int>> roads5 = {{0, 1, 1}, {1, 2, 2}};
    int n5 = 4;
    cout << "Test case 5 result: " << sol.countPaths(n5, roads5) << endl;  // Expected output: 0 (destination unreachable)

    return 0;
}
