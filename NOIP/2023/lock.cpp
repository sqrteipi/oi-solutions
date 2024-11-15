#include <bits/stdc++.h>
using namespace std;
map< vector<int> , int> s;
int main(){
    freopen("lock.in", "r", stdin);
    freopen("lock.out", "w", stdout);
    int n;
    cin >> n;
    for (int _=0; _<n; _++) {
        set< vector<int> > s2;
        vector<int> a(5);
        for (int i=0; i<5; i++) cin >> a[i];
        for (int i=0; i<5; i++) {
            for (int j=1; j<10; j++) {
                if (i + 1 < 5) {
                    a[i] = (a[i] + j) % 10;
                    a[i + 1] = (a[i + 1] + j) % 10;
                    s2.insert(a);
                    a[i] = (a[i] + 10 - j) % 10;
                    a[i + 1] = (a[i + 1] + 10 - j) % 10;
                }
                a[i] = (a[i] + j) % 10;
                s2.insert(a);
                a[i] = (a[i] + 10 - j) % 10;
            }
        }
        for (auto vec : s2) s[vec]++;
    }
    
    int cnt = 0;
    for (auto p : s) {
        if (n != p.second) continue;
        cnt++;
    }
    cout << cnt;
}