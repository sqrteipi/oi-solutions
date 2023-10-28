#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    int arr[n];
    vector<int> ans;
    for (int i=0; i<n; i++) cin >> arr[i];
    ans.push_back(arr[0]);
    for (int i=1; i<n; i++){
      if (arr[i]>=ans.back()) ans.push_back(arr[i]);
      else {ans.push_back(arr[i]); ans.push_back(arr[i]);}
    }
    cout << ans.size() << "\n";
    for (auto var:ans) cout << var << " ";
    cout << "\n";
    }
}
