// #include <bits/stdc++.h>
// using namespace std;

// struct SparseTable {
//     int n, LOG;
//     vector<int> log_table;
//     vector<vector<long long>> st_max, st_min;

//     SparseTable(const vector<long long>& arr) {
//         n = arr.size();
//         LOG = 32 - __builtin_clz(n);
//         log_table.assign(n + 1, 0);
//         for (int i = 2; i <= n; i++) log_table[i] = log_table[i / 2] + 1;

//         st_max.assign(LOG, vector<long long>(n));
//         st_min.assign(LOG, vector<long long>(n));
//         for (int i = 0; i < n; i++) {
//             st_max[0][i] = arr[i];
//             st_min[0][i] = arr[i];
//         }
//         for (int k = 1; k < LOG; k++) {
//             for (int i = 0; i + (1 << k) <= n; i++) {
//                 st_max[k][i] = max(st_max[k - 1][i], st_max[k - 1][i + (1 << (k - 1))]);
//                 st_min[k][i] = min(st_min[k - 1][i], st_min[k - 1][i + (1 << (k - 1))]);
//             }
//         }
//     }

//     long long query_max(int l, int r) {
//         int j = log_table[r - l + 1];
//         return max(st_max[j][l], st_max[j][r - (1 << j) + 1]);
//     }
//     long long query_min(int l, int r) {
//         int j = log_table[r - l + 1];
//         return min(st_min[j][l], st_min[j][r - (1 << j) + 1]);
//     }
// };

// long long SpecialSum(const vector<long long>& A, const vector<long long>& B, const vector<int>& K) {
//     int n = A.size(), m = B.size();
//     SparseTable st(B);
//     long long total_sum = 0;

//     for (int i = 0; i < n; i++) {
//         int start_j = max(1, i + 1 - K[i]);  // 1-based
//         int end_j = min(m, i + 1 + K[i]);    // 1-based
//         if (start_j > end_j) continue;

//         long long best;
//         if (A[i] >= 0)
//             best = st.query_max(start_j - 1, end_j - 1); // 0-based for st
//         else
//             best = st.query_min(start_j - 1, end_j - 1);

//         total_sum += A[i] * best;
//     }
//     return total_sum;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int T;
//     cin >> T;
//     while (T--) {
//         int N, M;
//         cin >> N >> M;
//         vector<long long> A(N), B(M);
//         vector<int> K(N);

//         for (int i = 0; i < N; i++) cin >> A[i];
//         for (int i = 0; i < M; i++) cin >> B[i];
//         for (int i = 0; i < N; i++) cin >> K[i];

//         cout << SpecialSum(A, B, K) << "\n";
//     }
// }



#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=4;
    bool flag=false;

    for(int i=0;i<n;i++){
        if(i%2==0){
            int cnt=0;
        for(int j=0;j<=i;j++){
            if(cnt==0) {
                cout<<0;
                cnt=1;
            }
            else if(cnt==1){
                cout<<1;
                cnt=0;
            }
        }
        cout<<endl;
    }
    else{
        int cnt=0;
        for(int j=0;j<=i;j++){
            if(cnt==0){
                cout<<1;
                cnt=1;
            }
            else if(cnt==1){
                cout<<0;
                cnt=0;
            }
            
        }
        cout<<endl;
    }
   }
    return 0;
}



// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n = 4;

//     for (int i = 0; i < n; i++) {
//         int cnt = (i % 2 == 0 ? 0 : 1); 
//         for (int j = 0; j <= i; j++) { 
//             cout << cnt;
//             cnt = 1 - cnt; 
//         }
//         cout << endl;
//     }
//     return 0;
// }
