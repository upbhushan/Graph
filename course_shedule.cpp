// #include<bits/stdc++.h>
// using namespace std;



// // question 1
// class solution{
//     public:
//     bool is_possible(int n,vector<vector<int>> &mat){
//         vector<vector<int>> adj(n);
//         for(auto ele:mat){
//             adj[ele[1]].push_back(ele[0]);
//         }

//         vector<int> indeg(n,0);

//         for(int i=0;i<n;i++){
//             for(auto node:adj[i]){
//                 indeg[node]++;
//             }
//         }

//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(indeg[i]==0){
//                 q.push(i);
//             }
//         }

//         int cnt=0;

//         while(!q.empty()){
//             auto node=q.front();
//             q.pop();
//             cnt++;

//             for(auto ele:adj[node]){
//                 indeg[ele]--;
//                 if(indeg[ele]==0){
//                     q.push(ele);
//                 }
//             }
//         }
//         return cnt==n;
//     }
// };


// //question 2

// class solution{
//     public:

//     vector<int> course_shedule(int n,vector<vector<int>> &mat){
//         vector<vector<int>> adj(n);
//         vector<int> indeg(n,0);
//         for(auto ele:mat){
//             adj[ele[1]].push_back(ele[0]);
//             indeg[ele[0]]++;
//         }

//         vector<int> ans;

//         queue<int> q;
//         for(int i=0;i<n;i++){
//             if(indeg[i]==0) {
//                 q.push(i);
//             }
//         }

//         while(!q.empty()){
//             auto node=q.front();
//             q.pop();

//             ans.push_back(node);

//             for(auto ele:adj[node]){
//                 indeg[ele]--;
//                 if(indeg[ele]==0){
//                     q.push(ele);
//                 }
//             }
//         }

//         if(ans.size()==n) return ans;
//         else return {};

//     }
// };

