#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floydWarshall(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<vector<int>> dist = mat;  // Initialize dist with input matrix

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {          // Intermediate vertex
            for (int i = 0; i < n; i++) {      // Source vertex
                for (int j = 0; j < n; j++) {  // Destination vertex
                    if (dist[i][k] != 1e9 && dist[k][j] != 1e9) {  // Check for valid paths
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        // Detect Negative Cycle
        bool hasNegativeCycle = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] < 0) {  // Negative cycle detected
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle) {
            cout << "Negative Cycle Detected!" << endl;
        } else {
            cout << "No Negative Cycle." << endl;
        }

        return dist;
    }
};

int main() {
    int INF = 1e9;
    vector<vector<int>> mat = {
        {0,   5,  INF, 10},
        {INF, 0,   3,  INF},
        {INF, INF, 0,   1},
        {INF, INF, INF, 0}
    };

    Solution obj;
    vector<vector<int>> result = obj.floydWarshall(mat);

    // Print Resulting Distance Matrix
    for (auto row : result) {
        for (auto val : row) {
            if (val == INF)
                cout << "INF" << " ";
            else
                cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
