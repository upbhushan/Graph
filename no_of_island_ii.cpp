#include<bits/stdc++.h>
using namespace std;

class DSU {
    public:
    vector<int> parent,rank;
    
    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int find_parent(int node){
        if(parent[node]==node) return node;
        else return parent[node]=find_parent(parent[node]);
    }
    
    void union_by_rank(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);
        
        if(ulp_u==ulp_v) return;
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u]=ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v]=ulp_u;
        }
        else {
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }
    
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        
        DSU ds(n*m);
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        vector<int> ans;
        int cnt=0;
        
        for(auto ele:operators){
            int row=ele[0];
            int col=ele[1];
            
            if(vis[row][col]==1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col]=1;
            cnt++;
            
            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                
                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol]==1){
                    int node_no=row*m+col;
                    int new_node_no=nrow*m+ncol;
                    if(ds.find_parent(node_no)!=ds.find_parent(new_node_no)){
                      cnt--;
                      ds.union_by_rank(node_no,new_node_no);
                    }
                    
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};