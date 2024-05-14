#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int n, m, cnt=0;
    cin >> n >> m;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    int k = *max_element(arr, arr+n), l = 1e9, r = -1;
    for (int i=0; i<n; i++) if (arr[i]==k) l = min(l, i), r = max(r, i);
    vector<pair<int, int>> pre, suf;
    for (int i=0; i<=l; i++) if (pre.empty()||pre.back().first<arr[i]) pre.push_back({arr[i], i});
    for (int i=n-1; i>=r; i--) if (suf.empty()||suf.back().first<arr[i]) suf.push_back({arr[i], i});
    for (int i=1; i<pre.size(); i++) cnt += max(pre[i].first-pre[i-1].first, abs(pre[i].second-pre[i-1].second));
    for (int i=1; i<suf.size(); i++) cnt += max(suf[i].first-suf[i-1].first, abs(suf[i].second-suf[i-1].second));
    cout << cnt + r - l;
}