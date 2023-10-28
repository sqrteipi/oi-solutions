#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  cin >> t;
  while (t--){
    cin >> n;
    int arr[n], arr2[n], p=n-1, valid=true;
    for (int i=0; i<n; i++) cin >> arr[i];
    for (int i=0; i<n; i++){
      if (i+1<=arr[p]) arr2[i] = p+1;
      else while (i+1>arr[p]) p--, arr2[i] = p+1;
    }
    for (int i=0; i<n; i++) if (arr[i]!=arr2[i]) valid = false;
    if (valid) cout << "YES\n";
    else cout << "NO\n";
  }
}
