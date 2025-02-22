#include<bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<pair<int, int>> adj[]) {
    // Min-heap for Prim's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Visited array
    vector<int> vis(V, 0);

    // Start from node 0
    pq.push({0, 0});
    int sum = 0;

    while (!pq.empty()) {
        pair<int, int> topElement = pq.top(); pq.pop();
        int wt = topElement.first;  // Extract weight
        int node = topElement.second;  // Extract node

        if (vis[node]) continue;

        vis[node] = 1;
        sum += wt;

        // Iterate through adjacent nodes
        for (auto it : adj[node]) {
            int edgw = it.first;    // Edge weight
            int adjNode = it.second; // Adjacent node

            if (!vis[adjNode]) {
                pq.push({edgw, adjNode});
            }
        }
    }

    return sum;
}