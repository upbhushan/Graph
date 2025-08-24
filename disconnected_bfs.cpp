#include<bits/stdc++.h>
using namespace std;

void bfs(int start,vector<vector<int>> &adj,vector<int> &res,vector<bool> &vis){
    queue<int> q;
    q.push(start);
    vis[start]=true;

    while(!q.empty()){
        int curr_ele=q.front();
        q.pop();
        res.push_back(curr_ele);

        for (int neighbor : adj[curr_ele]){
        if (!vis[neighbor]) {
            vis[neighbor] = true;
            q.push(neighbor);
        }
       }
    }
}

void bfsHelper(vector<vector<int>> &adj,vector<int> &res){
    int n=adj.size();
    vector<bool> vis(n,false);
    for(int i=0;i<n;i++){
        if(!vis[i]){
            bfs(i,adj,res,vis);
        }
    }
}

int main(){
    int n=5;
    vector<vector<int>> adj(n);
    adj[0].push_back(4);
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[3].push_back(4);

    
    vector<int> res;

    bfsHelper(adj,res);

    for(auto ele:res) cout<<ele<<" ";

    return 0;
}