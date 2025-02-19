#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> toposort(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> indeg(n, 0);
        queue<int> q;
        vector<int> ans;

        // Step 1: Compute in-degrees of all nodes
        for (int i = 0; i < n; i++) {
            for (int adjNode : adj[i]) {
                indeg[adjNode]++;
            }
        }

        // Step 2: Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        // Step 3: Process nodes in BFS order
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (int adjNode : adj[node]) {
                indeg[adjNode]--; // Reduce in-degree of adjacent nodes
                if (indeg[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }

        // If we processed all nodes, return result. Otherwise, there's a cycle.
        return (ans.size() == n) ? ans : vector<int>(); // Return empty if cycle exists
    }
};


