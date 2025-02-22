#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    int minimumEffortPath(vector<vector<int>>& heights){
        int n=heights.size();
        int m=heights[0].size();
        priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
        > pq;
        vector<vector<int>> dist(n,vector<int> (m,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,1,-1};

        while(!pq.empty()){
            auto ele=pq.top(); pq.pop();
            int diff=ele.first;
            int row=ele.second.first;
            int col=ele.second.second;

            if(row==n-1 && col==m-1){
                return diff;
            }

            for(int i=0;i<4;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int new_effort=max(abs(heights[row][col]-heights[nrow][ncol]),diff);
                    if(new_effort < dist[nrow][ncol]){
                        dist[nrow][ncol]=new_effort;
                        pq.push({new_effort,{nrow,ncol}});
                    }
                }
            }
        }
        return 0;

    }
};        