#include <bits/stdc++.h>
using namespace std;

int cnt[100000], dp[100001];
int main(){
  int n;
  cin >> n;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    cnt[x-1]++;
  }
  dp[1] = cnt[0];
  for (int i=2; i<100001; i++) {
    dp[i] = max(dp[i-2]+cnt[i-1]*i, dp[i-1]);
  }
  cout << dp[100000];
}
