#include <bits/stdc++.h>
using namespace std;
#define int long long
bool vis[8005][8005];
int cnt = 0;
signed main(){
    int n;
    string s;
    cin >> n >> s;
    queue< pair<int, int> > q;
    for (int i=0; i+1<n; i++) if (s[i] == s[i+1]) q.push({i, i+1});
    while (!q.empty() {
        int l = q.front().first, r = q.front().second; q.pop();
    }
}