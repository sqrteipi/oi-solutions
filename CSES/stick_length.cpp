#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a + n);
    int mid, ans = 0;
    if (n % 2 == 0) mid = (a[n/2-1] + a[n/2]) / 2;
    else mid = a[n/2];
    for (int i=0; i<n; i++) ans += abs(a[i] - mid);
    cout << ans;
}