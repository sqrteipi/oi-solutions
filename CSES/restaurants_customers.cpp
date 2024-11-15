#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    pair<int, int> v[n];
    multiset<int> s;
    for (int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }
    sort(v, v+n);
    int bst = 0;
    for (int i=0; i<n; i++) {
        auto [a, b] = v[i];
        s.insert(b);
        while (*s.begin() < a) s.erase(s.begin());
        bst = max(bst, (int) s.size());
    }
    cout << bst;
}