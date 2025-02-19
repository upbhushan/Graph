#include <bits/stdc++.h>
using namespace std;

//priority queue
class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int n, int src) {
        vector<int> dist(n, 1e9); 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto ele = pq.top(); 
            pq.pop();
            int distance = ele.first;
            int node = ele.second;

            // If already processed with a shorter distance, skip it
            if (distance > dist[node]) continue;

            // Traverse all adjacent nodes
            for (auto it : adj[node]) {
                int neighbor = it.first;
                int edgeWeight = it.second;

                // If a shorter path is found, update and push to priority queue
                if (dist[node] + edgeWeight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + edgeWeight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        return dist;
    }
};


//set

class solution{
    public:
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj,int n,int src){
        vector<int> dist(n,1e9);
        set<pair<int,int>> st;
        st.insert({0,src});
        dist[src]=0;

        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int distance=it.first;
            st.erase(it);

            for(auto ele:adj[node]){
                int adjNode=ele.first;
                int edgeweight=ele.second;

                if(dist[node]+edgeweight < dist[adjNode]){
                    if(dist[adjNode]!=1e9){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode]=dist[node]+edgeweight;
                    st.insert({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }

};