#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define int long long
#define i128 __int128
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>

#define REP1(a) for (int _ = 0; _ < a; ++_)
#define REP2(i, a) for (int i = 0; i < a; ++i)
#define REP3(i, a, b) for (int i = a; i < b; ++i)
#define REP4(i, a, b, c) for (int i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define REP(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)

#define pb push_back
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

template <class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;
template <class T> using max_heap = priority_queue<T>;

const int MOD = 1e9+7;
const int INF = 1e18;

int32_t main(){
  fast_io;
  int t;
  cin >> t;
  while (t--) {
    int n, d, k;
    cin >> n >> d >> k;
    int cnt[n + 1];
    REP(i, n + 1) cnt[i] = 0;
    while (k--) {
      int l, r;
      cin >> l >> r;
      l--; r--;
      cnt[l]++;
      cnt[r + 1]--; 
    }
    REP(i, 1, n + 1) cnt[i] += cnt[i-1];
    multiset<int> range;
    REP(i, k) range.insert(cnt[i]);
    int mn = INF, mx = -INF, mnind, mxind;
    REP(i, k, n) {
      range.insert(cnt[i]);
      cout << i << " ";
      int val = *range.rbegin();
      if (mn > val) mn = val, mnind = i - k + 1;
      if (val > mx) mx = val, mxind = i - k + 1;
      // cout << i - k << " ";
      // range.erase(range.lower_bound(cnt[i - k]));
    }
    cout << mxind << " " << mnind << "\n"; 
  }
}