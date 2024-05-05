#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<n; i++) cin >> b[i];
        int l=0, r=0, cnt=0;
        while (r<n) {
            if (l<n&&a[l]<=b[r]) l++;
            else cnt++;
            r++;
        }
        cout << cnt << "\n";
    }
}