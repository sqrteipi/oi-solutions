#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m, k; 
    cin >> n >> m >> k;
    int a[n], b[m];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];
    sort(a, a+n); sort(b, b+m);
    int r = 0, cnt = 0;
    for (int l = 0; l < n; l++) {
        while (r < m) {
            if (b[r] - k <= a[l] && a[l] <= b[r] + k) {r++; cnt++; break;}
            if (a[l] <= b[r] - k) break;
            r++;
        }
        if (r == m) break;
        
    }
    cout << cnt;
}