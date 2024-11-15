#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

pii G[200005], rG[200005];
vector<int> psum[200005];
int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    m = min(n, m);
    string s;
    cin >> s;
    int pre[n + n + 1] = {0};
    for (int i=0; i<n; i++) pre[i + 1] = pre[i] + (s[i] - '0');
    for (int i=0; i<n; i++) pre[n + i + 1] = pre[n + i] + (s[i] - '0');
    for (int i=0; i<n; i++) {
        int nxt = lower_bound(pre, pre + n + n + 1, pre[m + i + 1]) - pre;
        if (pre[i + 1] == pre[m + i + 1]) nxt = i + 2;
        int w = nxt - i - 1;
        if (nxt > n) nxt -= n;
        cout << i + 1 << " " << nxt << " " << w << "\n";
    }
}