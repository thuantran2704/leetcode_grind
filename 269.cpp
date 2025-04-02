#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

string alienOrder(vector<string>& words) {
    unordered_map<char, unordered_set<char>> graph;
    unordered_map<char, int> in_degree;

    // Step 1: Initialize in_degree for each unique character
    for (const string& word : words) {
        for (char c : word) {
            in_degree[c] = 0;  // Ensure every character exists in the in-degree map
        }
    }

    // Step 2: Build the graph
    for (size_t i = 0; i < words.size() - 1; i++) {
        string word1 = words[i], word2 = words[i + 1];
        size_t min_len = min(word1.length(), word2.length());

        // Invalid case: Prefix issue (e.g., "abc", "ab")
        if (word1.length() > word2.length() && word1.substr(0, min_len) == word2.substr(0, min_len)) {
            return "";
        }

        for (size_t j = 0; j < min_len; j++) {
            if (word1[j] != word2[j]) {
                if (graph[word1[j]].find(word2[j]) == graph[word1[j]].end()) {
                    graph[word1[j]].insert(word2[j]);
                    in_degree[word2[j]]++;  // Increase in-degree for dependent character
                }
                break;  // Only first differing character matters
            }
        }
    }

    // Step 3: Perform Topological Sort (Kahn's Algorithm - BFS)
    queue<char> q;
    string order;

    for (auto& [c, deg] : in_degree) {
        if (deg == 0) {
            q.push(c);
        }
    }

    while (!q.empty()) {
        char c = q.front();
        q.pop();
        order += c;

        for (char neighbor : graph[c]) {
            if (--in_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // Step 4: Validate and return result
    return order.size() == in_degree.size() ? order : "";
}

int main() {
    vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout << "Alien Dictionary Order: " << alienOrder(words) << endl;  // Output: "wertf"
    return 0;
}
