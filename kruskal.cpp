#include<bits/stdc++.h>
using namespace std;


class Disjoint{
    vector<int> parent,size,rank;
public:
    Disjoint(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++) parent[i]=i;
    }

    int find_parent(int node){
        if(node!=parent[node]){
            parent[node]=find_parent(parent[node]);
        }
        return parent[node];
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
        else{
            parent[ulp_u]=ulp_v;
            rank[ulp_v]++;
        }
    }

    void union_by_resize(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);

        if(ulp_u==ulp_v) return;
        else if(size[ulp_v] < size[ulp_u]){
            size[ulp_u]+=size[ulp_v];
            parent[ulp_v]=ulp_u;
        }
        else{
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};


int main() {
    int n, m;
    cin >> n >> m;  // n = number of nodes, m = number of edges

    vector<tuple<int, int, int>> edges; // {weight, u, v}

    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({wt, u, v});
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end());

    Disjoint ds(n);
    int mst_weight = 0;
    vector<pair<int, int>> mst_edges;

    for (auto &[wt, u, v] : edges) {
        if (ds.find_parent(u) != ds.find_parent(v)) {
            mst_weight += wt;
            mst_edges.push_back({u, v});
            ds.union_by_rank(u, v);  // You can also use union_by_size(u, v)
        }
    }

    cout << "Minimum Spanning Tree Weight: " << mst_weight << endl;
    cout << "Edges in MST:" << endl;
    for (auto &[u, v] : mst_edges) {
        cout << u << " - " << v << endl;
    }

    return 0;
}