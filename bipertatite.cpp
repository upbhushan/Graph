#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int node,int col,vector<int> &color,vector<vector<int>> &adj){
        color[node]=col;

        for(auto adjNode:adj[node]){
            if(color[adjNode]==-1){
                dfs(adjNode,!col,color,adj);
            }
            else if(color[adjNode]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        
        for (int i = 0; i < n; i++) { // Iterate through all nodes
            if (color[i] == -1) { // Start BFS for unvisited components
                queue<int> q;
                q.push(i);
                color[i] = 0;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (auto adjNode : adj[node]) {
                        if (color[adjNode] == -1) {
                            color[adjNode] = !color[node];
                            q.push(adjNode);
                        } else if (color[node] == color[adjNode]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
