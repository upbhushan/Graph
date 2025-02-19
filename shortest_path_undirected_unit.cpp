#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortest_path(vector<vector<int>> &edges, int N, int M, int src) {
        vector<vector<int>> adj(N);

        for (auto &ele : edges) {
            adj[ele[0]].push_back(ele[1]);
            adj[ele[1]].push_back(ele[0]);
        }

        vector<int> dist(N, 1e9);
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto adjNode : adj[node]) {
                if (dist[node] + 1 < dist[adjNode]) { 
                    dist[adjNode] = 1 + dist[node];
                    q.push(adjNode);
                }
            }
        }
        for (int i = 0; i < N; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        return dist;
    }
};
