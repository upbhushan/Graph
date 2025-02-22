#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    vector<int> bellaman_ford(vector<vector<int>> &edges)
    {
        int v = edges.size();
        vector<int> dist(v, 1e9);
        dist[0] = 0;

        for (int i = 0; i < v - 1; i++)
        {
            for (auto ele : edges)
            {
                int u = ele[0];
                int v = ele[1];
                int wt = ele[2];

                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }

            for (auto ele : edges)
            {
                int u = ele[0];
                int v = ele[1];
                int wt = ele[2];
                if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                {
                    return {-1};
                }
            }
        }
        return dist;
    }
};