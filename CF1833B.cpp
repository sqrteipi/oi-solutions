#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int t;
  cin >> t;
  while (t--){
    int n, m;
    cin >> n >> m;
    int arr[n], arr3[n], arr4[n];
    vector<pair<int, int>> arr2;
    for (int i=0; i<n; i++){
      cin >> arr[i];
      arr2.push_back({arr[i], i});
    }
    for (int i=0; i<n; i++){
      cin >> arr3[i];
    }
    sort(arr2.begin(), arr2.end());
    sort(arr3, arr3+n);
    for (int i=0; i<n; i++){
      arr4[arr2[i].second] = arr3[i];
    }
    for (int i=0; i<n; i++) cout << arr4[i] << " ";
    cout << "\n";
  }
}
