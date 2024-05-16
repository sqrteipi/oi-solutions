#include <bits/stdc++.h>
using namespace std;

int xorpre[200005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> xorpre[i], xorpre[i] ^= xorpre[i-1];
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << (xorpre[l-1] ^ xorpre[r]) << "\n";
    }
}