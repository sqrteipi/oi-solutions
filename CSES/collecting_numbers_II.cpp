#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0, n, q;
    cin >> n >> q;
    int a[n], pos[n + 1];
    for (int i=0; i<n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i=1; i<=n; i++) if (i == 1 || pos[i] < pos[i-1]) ans++;
    while (q--) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        if (a[x] > a[y]) swap(x, y);
        int x2 = a[x], y2 = a[y];
        if (x2 == 1 || pos[x2] < pos[x2 - 1]) ans--;
        if (x2 < n && pos[x2 + 1] < pos[x2]) ans--;
        if (y2 == 1 || pos[y2] < pos[y2 - 1]) ans--;
        if (y2 < n && pos[y2 + 1] < pos[y2]) ans--;
        if (x2 + 1 == y2 && pos[x2] > pos[y2]) ans++;
        pos[x2] = y; pos[y2] = x; swap(a[x], a[y]);
        if (x2 == 1 || pos[x2] < pos[x2 - 1]) ans++;
        if (x2 < n && pos[x2 + 1] < pos[x2]) ans++;
        if (y2 == 1 || pos[y2] < pos[y2 - 1]) ans++;
        if (y2 < n && pos[y2 + 1] < pos[y2]) ans++;
        if (x2 + 1 == y2 && pos[x2] > pos[y2]) ans--;
        cout << ans << "\n";
    }
}