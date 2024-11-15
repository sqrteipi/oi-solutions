#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    int gp[n + 1], sz = 1, diff = 1;
    map<int, int> freq2;
    for (int i=1; i<=n; i++) gp[i] = 1;
    freq2[1] = n;
    for (int i=1; i<=m; i++) {
        int k;
        cin >> k;
        map<int, vector<int>> mp;
        while (k--) {
            int v;
            cin >> v;
            mp[gp[v]].push_back(v);
        }
        for (auto [val, vec] : mp) {
            if (vec.size() == freq2[val]) continue;
            sz++; diff++; freq2[val] -= vec.size(); freq2[sz] = vec.size();
            for (auto var : vec) gp[var] = sz;
        }
        if (diff == n) {
            cout << i;
            return 0;
        }
    }
    cout << "Impossible";
}