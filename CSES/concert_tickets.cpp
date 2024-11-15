#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    multiset<int> s;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i], s.insert(a[i]);
    while (m--) {
        int v;
        cin >> v;
        auto loc = s.upper_bound(v);
        if (loc == s.begin()) cout << -1 << "\n";
        else cout << *(--loc) << "\n", s.erase(loc);
    }
}