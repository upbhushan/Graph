#include<bits/stdc++.h>
using namespace std;

class solution{
public:
//bfs
bool detect_cycle(int src,vector<int> &vis,vector<vector<int>> &adj){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});

    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();

        for(auto adjnode:adj[node]){
            if(!vis[adjnode]){
                q.push({adjnode,node});
            }
            else if(parent!=adjnode){
                return true;
            }
        }
    }
    return false;
}
//dfs

bool detect_cycle(int src,int parent,vector<int> &vis,vector<vector<int>> &adj){
    vis[src]=1;

    for(auto adjnode:adj[src]){
        if(!vis[adjnode]){
            if(detect_cycle(adjnode,src,vis,adj)){
                return true;
            }
        }
        else if(adjnode!=parent){
            return true;
        }
    }
    return false;
}
bool cycle(vector<vector<int>>&adj){
    int n=adj.size();
    vector<int> vis(n,0);
    for(int i=0;i<n;i++){
        //bfs
        if (!vis[i]) {
            if (detect_cycle(i, vis, adj)) return true;
        }
        //dfs
        if (!vis[i]) {
            if (detect_cycle(i,-1,vis,adj)) return true;
        }
    }
    return false;
}
};