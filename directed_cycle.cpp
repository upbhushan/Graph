#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs_check(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs_check(adjNode, adj, vis, pathvis)) return true;
            } 
            else if (pathvis[adjNode]) { // Back edge detected (cycle exists)
                return true;
            }
        }

        pathvis[node] = 0; // Backtrack
        return false;
    }

    bool hasCycle(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0), pathvis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs_check(i, adj, vis, pathvis)) return true;
            }
        }
        return false;
    }
};
