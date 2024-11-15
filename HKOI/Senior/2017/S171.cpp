#include <bits/stdc++.h>
using namespace std;
bool pw[100005];
int tv[100005];
queue<pair<int, int>> qu[100005];
vector<int> ch[100005];
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        ch[i].resize(v);
        for (int j=0; j<v; j++) cin >> ch[i][j];
    }
    for (int i=0; i<m; i++) cin >> pw[i] >> tv[i];
    while (q--) {
        int a, b, c;
        cin >> a >> b >> c;
        pw[b - 1] ^= 1;
        qu[tv[b - 1]].push({a, pw[b]});
    }
    for (int v=0; v<n; v++) {
        int l = 0;
        for (int i=0; i<ch[v].size(); i++) {
            int r = l + ch[v][i], ans = 0;
            l = r;
            // cout << ans << "\n";
            cout << fixed << setprecision(9) << ans * 1.0 / ch[v][i] << " ";
        }
    }
}