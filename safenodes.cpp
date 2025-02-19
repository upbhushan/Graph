#include <bits/stdc++.h>
using namespace std;

//method 1
class Solution {
public:
    bool dfs_check(int node, vector<vector<int>> &adj, vector<int> &vis, 
                   vector<int> &pathvis, vector<int> &check) {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs_check(adjNode, adj, vis, pathvis, check)) {
                    check[node] = 0;
                    return true;
                }
            } 
            else if (pathvis[adjNode]) { // Cycle detected
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1;  // Node is safe
        pathvis[node] = 0; // Backtrack
        return false;
    }

    vector<int> solve(vector<vector<int>> &adj) {
        int n = adj.size();
        vector<int> vis(n, 0), pathvis(n, 0), check(n, 0);
        vector<int> safe_nodes;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs_check(i, adj, vis, pathvis, check);
            }
        }

        for (int i = 0; i < n; i++) {
            if (check[i] == 1) {
                safe_nodes.push_back(i);
            }
        }

        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
};


//method 2

class solution{
public:
    vector<int> safe_node(vector<vector<int>> &adj){
        int n=adj.size();
        vector<int> indeg(n);
        vector<vector<int>> rev_adj(n);
        for(int i=0;i<n;i++){
            for(auto node:adj[i]){
            rev_adj[node].push_back(i);
            indeg[i]++;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto ele:rev_adj[node]){
                indeg[ele]--;
                if(indeg[ele]==0){
                    q.push(ele);
                }
            }
        }
        return ans;
    }
};