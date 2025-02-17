#include <bits/stdc++.h>
using namespace std;

class solution {
public:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &adj) {
        vis[row][col] = 1;
        int n = adj.size();
        int m = adj[0].size();
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && adj[nrow][ncol] == 'O') {
                dfs(nrow, ncol, vis, adj);
            }
        }
    }

    void solve(vector<vector<char>> &adj) {
        int n = adj.size();
        int m = adj[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Process boundary rows
        for (int j = 0; j < m; j++) {
            //first row
            if (!vis[0][j] && adj[0][j] == 'O') dfs(0, j, vis, adj);
            //last row
            if (!vis[n - 1][j] && adj[n - 1][j] == 'O') dfs(n - 1, j, vis, adj);
        }

        // Process boundary cols
        for (int i = 0; i < n; i++) {
            //first col
            if (!vis[i][0] && adj[i][0] == 'O') dfs(i, 0, vis, adj);
            //last col
            if (!vis[i][m - 1] && adj[i][m - 1] == 'O') dfs(i, m - 1, vis, adj);
        }

        // Convert unvisited 'O' to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && adj[i][j] == 'O') {
                    adj[i][j] = 'X';
                }
            }
        }
    }
};
