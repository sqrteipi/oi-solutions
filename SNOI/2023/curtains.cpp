#include <bits/stdc++.h>
using namespace std;
bool ans[500005];
int main(){
    set<int> covered;
    int n, m, q;
    cin >> n >> m >> q;
    pair<int, int> cu[m];
    for (int i=0; i<m; i++) {
        int l, r;
        cin >> l >> r;
        cu[i] = {l, r};
    }
    sort(cu, cu+m);
    for (int i=0; i<m; i++) {
        int l = cu[i].first, r = cu[i].second;
        if (l==1) {
            ans[r] = true;
            covered.insert(r);
            continue;
        }
        if (covered.empty()) continue;
        int k = *covered.rbegin();
        if (l<=k) {
            ans[r] = true;
        }
    }
}