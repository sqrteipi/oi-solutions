#include <bits/stdc++.h>
using namespace std;
int main(){
    int ans = 0, n;
    cin >> n;
    int a[n], pos[n + 1];
    for (int i=0; i<n; i++) cin >> a[i], pos[a[i]] = i;
    for (int i=1; i<=n; i++) if (i == 1 || pos[i] < pos[i-1]) ans++;
    cout << ans;
}