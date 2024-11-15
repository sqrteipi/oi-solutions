#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    vector<int> w = {0};
    int pw = 1, i = 1;
    while (pw * 10 * i <= 1e18) {
        w.push_back(w.back() + pw * 9 * i);
        pw *= 10; i++;
    }
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        int v = lower_bound(w.begin(), w.end(), n) - w.begin();
        int ls = pow(10, v - 1);
        string s = to_string((n - w[v - 1] + v - 1) / v + ls - 1);
        cout << s[(n - w[v - 1] + v - 1) % v] << "\n";
    }
}