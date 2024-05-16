#include <bits/stdc++.h>
using namespace std;

vector<int> seg(800005, 0);
int arr[200005];
void build(int index, int l, int r) {
    if (l==r) seg[index] = arr[l];
    else {
        int mid = (l+r)/2;
        build(index*2, l, mid);
        build(index*2+1, mid+1, r);
        seg[index] = min(seg[index*2], seg[index*2+1]);
    }
}

int query(int index, int l, int r, int ql, int qr) {
    if (r<ql||l>qr) return 2e9;
    if (l>=ql&&r<=qr) return seg[index];
    else {
        int mid = (l+r)/2;
        return min(query(index*2, l, mid, ql, qr), query(index*2+1, mid+1, r, ql, qr));
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> arr[i];
    build(1, 1, n);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l, r) << "\n";
    }
}