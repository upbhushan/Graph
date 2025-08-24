#include <bits/stdc++.h>
using namespace std;

class disjoint{
    vector<int> rank,parent,size;

public:
    disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
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

    void union_by_size(int u,int v){
        int ulp_u=find_parent(u);
        int ulp_v=find_parent(v);

        if(ulp_u==ulp_v) return;

        else if(size[ulp_u] < size[ulp_v]){
            size[ulp_v]+=size[ulp_u];
            parent[ulp_u]=ulp_v;
        }
    }
};

class Disjoint
{
    vector<int> rank, parent, size;

public:
    Disjoint(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int find_parent(int node)
    {
        if (node != parent[node])
        {
            parent[node] = find_parent(parent[node]); // Path compression
        }
        return parent[node];
    }

    void union_by_rank(int u, int v)
    {
        int ultimate_parent_u = find_parent(u);
        int ultimate_parent_v = find_parent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;

        if (rank[ultimate_parent_u] < rank[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
        }
        else if (rank[ultimate_parent_v] < rank[ultimate_parent_u])
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
        }
        else
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            rank[ultimate_parent_v]++;
        }
    }

    void union_by_size(int u, int v)
    {
        int ultimate_parent_u = find_parent(u);
        int ultimate_parent_v = find_parent(v);
        if (ultimate_parent_u == ultimate_parent_v)
            return;
        else if (size[ultimate_parent_u] < size[ultimate_parent_v])
        {
            parent[ultimate_parent_u] = ultimate_parent_v;
            size[ultimate_parent_v] += size[ultimate_parent_u];
        }
        else
        {
            parent[ultimate_parent_v] = ultimate_parent_u;
            size[ultimate_parent_u] += size[ultimate_parent_v];
        }
    }
};

int main()
{
    disjoint ds(7);
    // ds.union_by_size(1, 2);
    // ds.union_by_size(2, 3);
    // ds.union_by_size(4, 5);
    // ds.union_by_size(6, 7);
    // ds.union_by_size(5, 6);

    ds.union_by_rank(1, 2);
    ds.union_by_rank(2, 3);
    ds.union_by_rank(4, 5);
    ds.union_by_rank(6, 7);
    ds.union_by_rank(5, 6);

    if (ds.find_parent(3) == ds.find_parent(7))
    {
        cout << "same\n";
    }
    else
    {
        cout << "not same\n";
    }

    ds.union_by_rank(3, 7);

    if (ds.find_parent(3) == ds.find_parent(7))
    {
        cout << "same\n";
    }
    else
    {
        cout << "not same\n";
    }

    return 0;
}
