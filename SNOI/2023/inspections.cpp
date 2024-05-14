#include <bits/stdc++.h>
using namespace std;
#define int long long
int last[4000005], last_used[200005];
int32_t main() {
    int n, m, q, time=0, mac=0;
    cin >> n >> m >> q;
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        for (int j=l; j<=r; j++) {
            time++; mac++;
            if (last_used[j]==0) last_used[j] = time;
            else last[time-last_used[j]]++, last_used[j] = time;
        }
    }
    for (int i=1; i<=n*n; i++) last[i] += last[i-1];
    while (q--) {
        int x;
        cin >> x;
        if (x>=4000005) cout << "0 ";
       else  cout << last[n*n]-last[x] << " ";
    }
}