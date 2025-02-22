#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            // Check if starting or ending cell is blocked
            if (grid[0][0] != 0 || grid[n - 1][m - 1] != 0) return -1;
    
            // Distance matrix initialized to a large value
            vector<vector<int>> dist(n, vector<int>(m, 1e9));
            queue<pair<int, pair<int, int>>> q;
    
            // Starting point with distance 1
            dist[0][0] = 1;
            q.push({1, {0, 0}});
    
            // All 8 possible directions
            vector<int> dx = {1, -1, 0, 0, 1, -1, 1, -1};
            vector<int> dy = {0, 0, 1, -1, 1, 1, -1, -1};
    
            while (!q.empty()) {
                auto ele = q.front(); q.pop();
                int distance = ele.first;
                int curr_row = ele.second.first;
                int curr_col = ele.second.second;
    
                // Check if destination is reached
                if (curr_row == n - 1 && curr_col == m - 1) {
                    return distance;
                }
    
                // Explore all 8 directions
                for (int i = 0; i < 8; i++) {
                    int nrow = curr_row + dx[i];
                    int ncol = curr_col + dy[i];
    
                    // Check bounds and if the cell is unblocked
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 0) {
                        if (distance + 1 < dist[nrow][ncol]) {
                            dist[nrow][ncol] = distance + 1;
                            q.push({distance + 1, {nrow, ncol}});
                        }
                    }
                }
            }
    
            return -1; 
        }
    };