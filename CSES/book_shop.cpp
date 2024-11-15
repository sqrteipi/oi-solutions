#include <bits/stdc++.h>
using namespace std;
int dp[1005][100005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int a[n+1], b[n+1];
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    for (int i=1; i<=n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if (j >= a[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i]] + b[i]);
        }
    }
    cout << dp[n][m];
}