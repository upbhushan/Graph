#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> bellman_ford(int v, vector<vector<int>> &edges, int src)
    {
        vector<int> dist(v, 1e9);
        dist[src] = 0;

        // Relax all edges (V-1) times
        for (int i = 0; i < v - 1; i++)
        {
            for (auto &ele : edges)
            {
                int u = ele[0];
                int v = ele[1];
                int wt = ele[2];

                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // **Negative Cycle Detection 
        for (auto &ele : edges)
        {
            int u = ele[0];
            int v = ele[1];
            int wt = ele[2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
            {
                return {-1}; // Negative cycle detected
            }
        }

        return dist;
    }
};
