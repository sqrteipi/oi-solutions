#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int a[n][k], b[n][k];
    for (int i=0; i<n; i++) for (int j=0; j<k; j++) cin >> a[i][j];
    for (int i=0; i<n; i++) for (int j=0; j<k; j++) cin >> b[i][j];
    if (n==1) {
        bool ok = true;
        for (int i=0; i<n; i++) if (a[0][i]>0) ok = false;
        if (ok) cout << 1;
        else cout << 0;
    }
    else if (k==1) {
        vector<pair<int, int>> arr;
        for (int i=0; i<n; i++) arr.push_back({a[i][0], b[i][0]});
        sort(arr.begin(), arr.end());
        int cnt=0, k=0;
        for (int i=0; i<n; i++) if (k>=arr[i].first) k += arr[i].second, cnt++;
        cout << cnt;
    }
    else {
        int kn[k], cnt=0;
        bool used[n];
        for (int i=0; i<k; i++) kn[i] = 0;
        for (int i=0; i<n; i++) used[i] = false;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) if (!used[j]) {
                bool ok = true;
                for (int v=0; v<k; v++) if (a[j][v]>kn[v]) ok = false;
                if (ok) {
                    cnt++;
                    used[j] = true;
                    for (int v=0; v<k; v++) kn[v] += b[j][v];
                }
            }
        }
        cout << cnt;
    }
}