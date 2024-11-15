#include <bits/stdc++.h>
using namespace std;

int f(int x, int md) {
    if (md == 3) return x * (x + 1) / 2;
    if (md == 4) return x * x;
    if (md == 5) return x * (3 * x - 1) / 2;
    if (md == 6) return x * (2 * x - 1);
    if (md == 7) return x * (5 * x - 3) / 2;
    if (md == 8) return x * (3 * x - 2);
    return -1;
}

int main(){
    map<string, int> mp;
    for (int md=3; md<=8; md++) {
        for (int i=1; i<=1000; i++) if (1 < f(i, md) && f(i, md) < 10000) {
            string s = to_string(f(i, md));
            if (s.length() < 4) s += "0";
            sort(s.begin(), s.end());
            mp[s]++;
        }
    }
    for (auto [str, val] : mp) if (val >= 6) cout << str << " ";
    // int cnt = 0;
    // for (int md=3; md<=8; md++) {
    //     for (int i=1; i<=1000; i++) if (f(i, md) && f(i, md) < 10000) {
    //         string s = to_string(f(i, md));
    //         if (s.length() < 4) s += "0";
    //         sort(s.begin(), s.end());
    //         if (mp[s] >= 6) cout << f(i, md) << " ";
    //     }
    // }
    // cout << cnt;
}