#include <bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    int parity = arr[0]%2;
    bool valid=true;
    for (int i=1; i<n; i++) {
      if (parity==arr[i]%2||(arr[i]-arr[0])%2!=parity) valid = false;
    }
    if (valid) cout << "YES\n";
    else cout << "NO\n";
  }
}
