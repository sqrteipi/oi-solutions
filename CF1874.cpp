#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main() {
  int t;
  cin >> t;
  while (t--){
    int n, m, k;
    vector<int> j, g;
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
      int ai; cin >> ai; j.push_back(ai);
    }
    for (int i=0; i<m; i++){
      int bi; cin >> bi; g.push_back(bi);
    }
    sort(j.begin(), j.end());
    sort(g.begin(), g.end());
    int min_val=min(j[0], g[0]), max_val=max(j[n-1], g[m-1]), r=0; 
    while ((j[0]!=min_val || g[m-1]!=max_val || r%2==1) && r<=k){
      if (r%2==0){ //Jelly's Turn
        if (j[0]<g[m-1]){ // Swap!
          swap(j[0], g[m-1]);
          for (int i=0; (i<n-1&&j[i]>j[i+1]); i++) swap(j[i], j[i+1]);
          for (int i=m-1; (i>0&&g[i]<g[i-1]); i--) swap(g[i], g[i-1]);
        }
      } 
      else{
        if (g[0]<j[n-1]){
          swap(g[0], j[n-1]);
          for (int i=0; (i<m-1&&g[i]>g[i+1]); i++) swap(g[i], g[i+1]);
          for (int i=n-1; (i>0&&j[i]<j[i-1]); i--) swap(j[i], j[i-1]);
        } 
      }
      r++;
    }
    if (k%2==1){
      swap(j[0], g[m-1]);
    }
    int cnt = 0;
    for (int i=0; i<n; i++) cnt += j[i];
    cout << cnt << "\n";
  }
}
