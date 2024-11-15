#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i=0; i<n; i++)

#define int long long
#define i128 __int128
#define ff first
#define ss second
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>

#define pb push_back
#define min_heap priority_queue<pii, vector<pii>, greater<pii>>
#define fast_io ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

const int MOD = 1e9+7;
const int INF = 1e18;

i128 read() {
  i128 x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}

void print(i128 x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x > 9) print(x / 10);
  putchar(x % 10 + '0');
}

struct DSU {
  vi p;
  DSU (int n) { REP(i, n + 5) p.pb(i); }
  int find (int n) { return (p[n] == n ? n : p[n] = find(p[n])); }
  int unite(int u, int v) {
    if (find(u) == find(v)) return false;
    p[find(v)] = u;
    return true;
  }
  bool eq(int u, int v) { return find(u) == find(v); }
};

struct segTree {
  vi seg, lazy, arr;
  segTree(int n, vi arr2) { seg.resize(4*n+10); lazy.resize(4*n+10); REP(i, 4*n+10) seg.pb(0), lazy.pb(0); arr = arr2;}
  void build(int ind, int l, int r) {
    if (l == r) seg[ind] = arr[l];
    else {
      int mid = (l + r) / 2;
      build(ind * 2, l, mid);
      build(ind * 2 + 1, mid + 1, r);
      seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]); // Function
    }
  }
  int query(int ind, int l, int r, int ql, int qr) {
    if (r < ql || qr < l) return -INF; // Out of Bound
    if (ql <= l && r <= qr) return seg[ind]; // Fully Covered
    // Lazy Propagation
    seg[ind * 2] += lazy[ind];
    seg[ind * 2 + 1] += lazy[ind];
    lazy[ind * 2] += lazy[ind];
    lazy[ind * 2 + 1] += lazy[ind];
    lazy[ind] = 0;
    // Continue Visit
    int mid = (l + r) / 2;
    return max(query(ind * 2, l, mid, ql, qr), query(ind * 2 + 1, mid + 1, r, ql, qr));
  }
  void push(int ind, int l, int r, int ql, int qr, int val) {
    if (r < ql || qr < l) return; // Out of Bound
    if (ql <= l && r <= qr) { // Fully Covered
      seg[ind] += val;
      lazy[ind] += val;
      return;
    } 
    int mid = (l + r) / 2;
    push(ind * 2, l, mid, ql, qr, val);
    push(ind * 2 + 1, mid + 1, r, ql, qr, val);
    seg[ind] = max(seg[ind * 2], seg[ind * 2 + 1]);
  }
};

vvi readGraph(int n, int m, int op) { // op1 = Undirected, op2 = directed
  vvi G(n + 1, vi());
  while (m--) {
    int u, v;
    cin >> u >> v;
    G[u].pb(v);
    if (op == 2) G[v].pb(u);
  }
  return G;
}

int32_t main(){
  fast_io;
}