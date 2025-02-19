#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis,stack<int> &st){
        vis[node]=1;
        
        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode,adj,vis,st);
            }
        }
        st.push(node);

    }

    vector<int> topo(vector<vector<int>> &adj){
        int n=adj.size();
        vector<int> vis(n,0);
        stack<int> st;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};