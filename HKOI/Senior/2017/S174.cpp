#include <bits/stdc++.h>
using namespace std;
#define int long long

int a, b;
int bst(vector<int> V) {
    int n = V.size(), bstcost = 1e9, bstind = 0;
    for (int i=0; i<=128; i++) {
        int cost = 0;
        for (auto var : V) {
            if (var >= i) cost += (var - i) * b;
            else cost += (i - var) * a;
        }
        if (bstcost > cost) bstcost = cost, bstind = i;
    }
    return bstind;
}

vector<vector<int>> solve(vector<vector<int>> G, int n){
    int arr[n][n];
    arr[0][0] = 1;
    arr[1][0] = 2;
    arr[1][1] = 3;
    for (int i=2; i<n; i++) {
        for (int j=1; j<i; j++) arr[i][j] = 6 - arr[i-1][j-1] - arr[i-1][j];
        arr[i][0] = 6 - arr[i-1][0] - arr[i][1];
        arr[i][i] = 6 - arr[i-1][i-1] - arr[i][i-1];
    }
    for (int i=0; i<n; i++) for (int j=0; j<=i; j++) arr[i][j]--;
    vector<int> V[3];
    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) V[arr[i][j]].push_back(G[i][j]);
    }
    int cost = 0;
    for (int i=0; i<3; i++) {
        int bstind = bst(V[i]);
        for (int j=0; j<n; j++) {
            for (int k=0; k<=j; k++) if (arr[j][k] == i) G[j][k] = bstind;
        }
    }
    return G;
}

int32_t main(){
    int n, k;
    cin >> n >> a >> b >> k;
    vector<vector<int>> G(n);
    for (int i=0; i<n; i++) {
        G[i].resize(i + 1);
        for (int j=0; j<=i; j++) cin >> G[i][j];
    }
    for (int i=0; i<k; i++) {
        for (int j=0; j<=i; j++) {
            vector<vector<int>> G2;
            for (int v1=i; v1<n; v1+=k) {
                G2.push_back({});
                for (int v2=j; v2<=v1; v2+=k) G2.back().push_back(G[v1][v2]);
            }
            if (G2.size() == 1) continue;
            vector<vector<int>> ans = solve(G2, G2.size());
            for (auto vec : ans) {
                for (auto var : vec) cout << var << " ";
                cout << "\n";
            }
        }
    }
}