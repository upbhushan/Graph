#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void topo_sort(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;
        for (auto ele : adj[node]) {
            int v = ele.first;
            if (!vis[v]) {
                topo_sort(v, adj, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortest_path(int V, int E, vector<vector<int>> &edges) {
        vector<pair<int, int>> adj[V];  // Correct adjacency list

        // Correctly adding edges to the adjacency list
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }

        vector<int> vis(V, 0);
        stack<int> st;

        // Perform Topological Sort
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topo_sort(i, adj, vis, st);
            }
        }

        // Initialize distances
        vector<int> dist(V, 1e9);
        dist[0] = 0;  // Assuming 0 is the source

        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (dist[node] != 1e9) {
                for (auto ele : adj[node]) {
                    int v = ele.first;
                    int wt = ele.second;

                    if (dist[node] + wt < dist[v]) {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // Convert unreachable nodes' distances to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};



   
