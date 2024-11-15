#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int bst = -1e18, cur = 0;
    for (int i=0; i<n; i++) cur = max(a[i], a[i] + cur), bst = max(bst, cur);
    cout << bst;
}