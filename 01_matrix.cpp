#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    vector<vector<int>> update_matrix(vector<vector<int>> &mat){
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dist(n,vector<int> (m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    dist[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};

        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=x+dx[i];
                int ncol=y+dy[i];

                if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && mat[nrow][ncol]==-1){
                    dist[nrow][ncol]=dist[x][y]+1;
                    q.push({nrow,ncol});
                }
            }
            
        }
        return dist;
    }
};