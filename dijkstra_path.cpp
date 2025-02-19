#include<bits/stdc++.h>
using namespace std;

class solution{
public:
    vector<int> dijkstra_path(vector<vector<pair<int, int>>> &adj, int n, int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,1});
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        dist[1]=0;
        
        while(!pq.empty()){
            auto ele=pq.top(); pq.pop();
            int distance=ele.first;
            int node=ele.second;

            for(auto adjNode:adj[node]){
                int neighbour=adjNode.first;
                int edgw=adjNode.second;

                if(dist[node]+edgw < dist[neighbour]){
                    dist[neighbour]=dist[node]+edgw;
                    pq.push({dist[node]+edgw,neighbour});
                    parent[neighbour]=node;
                }
            }
        }
        if(dist[n]==1e9) return {-1};
        vector<int> path;
        int node=n;

        while(parent[node]!=node){
            path.push_back(node);
            node=parent[node];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        return path;
    }
};