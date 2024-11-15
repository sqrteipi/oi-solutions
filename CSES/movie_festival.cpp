#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second == p2.second) return p1.first < p2.first;
    return p1.second < p2.second;
}

int main(){
    int n;
    cin >> n;
    pair<int, int> v[n];
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v, v+n, cmp);
    int last = -1, cnt = 0;
    for (auto [a, b] : v) if (a >= last) cnt++, last = b;
    cout << cnt;
}