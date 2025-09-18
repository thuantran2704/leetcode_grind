class Solution {
public:
    bool dfs(int start, int target, vector<vector<int>>& graph, vector<int>& seen) {
        if (start == target) return true;
        if (seen[start]) return false;
        seen[start] = 1;

        for (int nei : graph[start]) {
            if (dfs(nei, target, graph, seen)) return true;
        }
        return false;
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(numCourses);

        // build adjacency list
        for (auto& pre : prerequisites) {
            graph[pre[0]].push_back(pre[1]);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            vector<int> seen(numCourses, 0);
            ans.push_back(dfs(q[0], q[1], graph, seen));
        }
        return ans;
    }
};
