class Solution {
    public:
        // squared Euclidean distance
        int euclDist(vector<int>& a) {
            return a[0]*a[0] + a[1]*a[1];
        }
    
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            // max-heap: store (distance, index)
            priority_queue<pair<int,int>> pq;
    
            for (int i = 0; i < points.size(); i++) {
                int dist = euclDist(points[i]);
                pq.push({dist, i});
                if (pq.size() > k) pq.pop(); // keep only k closest
            }
    
            vector<vector<int>> res;
            while (!pq.empty()) {
                res.push_back(points[pq.top().second]);
                pq.pop();
            }
            return res;
        }
    };
    