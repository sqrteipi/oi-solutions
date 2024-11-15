#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, ans = 0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int l = 0;
    set<int> s;
    for (int r=0; r<n; r++) {
        while (s.count(a[r])) s.erase(a[l]), l++;
        s.insert(a[r]);
        ans = max(ans, (int) s.size());
    }
    cout << ans;
}