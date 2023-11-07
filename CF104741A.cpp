#include <bits/stdc++.h>
using namespace std;
#define int long long
long long convert(string n, int base){
  long long cnt=0;
  for (int i=n.length()-1; i>=0; i--) {
    if (n[i]>='A') cnt += ((int) n[i]-'A'+10) * pow(base, n.length()-i-1);
    else cnt += ((int) n[i]-'0') * pow(base, n.length()-i-1);
  }
  return cnt;
}

int32_t main() {
  int t;
  cin >> t;
  while (t--){
    string a, b, s;
    char maxi=' ';
    cin >> a >> b >> s;
    for (int i=0; i<a.length(); i++) maxi = max(maxi, a[i]);
    for (int i=0; i<b.length(); i++) maxi = max(maxi, b[i]);
    for (int i=0; i<s.length(); i++) maxi = max(maxi, s[i]);
    if (maxi>='A') maxi = maxi - 'A' + 10;
    else maxi -= '0';
    for (int i=maxi+1; i<=16; i++){
      long long c=convert(a, i), d=convert(b, i), e=convert(s, i);
      if (c+d==e) {cout << i << "\n"; break;}
    }
  }
}
