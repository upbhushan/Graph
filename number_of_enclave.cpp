#include <bits/stdc++.h>
using namespace std;

class solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &adj)
    {
        vis[row][col] = 1;
        int n = vis.size();
        int m = vis[0].size();
        int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && adj[nrow][ncol] == 1)
            {
                dfs(nrow, ncol, vis, adj);
            }
        }
    }
    int count_no_of_enclaves(vector<vector<int>> &adj)
    {
        int n = adj.size();
        int m = adj[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        // roows
        for (int j = 0; j < m; j++)
        {
            // first row
            if (!vis[0][j] && adj[0][j] == 1)
            {
                dfs(0, j, vis, adj);
            }
            // last row
            if (!vis[n - 1][j] && adj[n - 1][j] == 1)
            {
                dfs(n - 1, j, vis, adj);
            }
        }

        // cols
        for (int i = 0; i < n; i++)
        {
            // first col
            if (!vis[i][0] && adj[i][0] == 1)
            {
                dfs(i, 0, vis, adj);
            }
            // last col
            if (!vis[i][m - 1] && adj[i][m - 1] == 1)
            {
                dfs(i, m - 1, vis, adj);
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (adj[i][j] == 1 && !vis[i][j])
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};