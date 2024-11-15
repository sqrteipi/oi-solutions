#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    map<string, int> mp;
    for (int i=1; i<=1e4; i++) {
        string s = to_string(i * i * i);
        sort(s.begin(), s.end());
        mp[s]++;
    }
    for (int i=1; i<=1e4; i++) {
        string s = to_string(i * i * i);
        sort(s.begin(), s.end());
        if (mp[s] == 5) {
            cout << i;
            return 0;
        }
    }
}