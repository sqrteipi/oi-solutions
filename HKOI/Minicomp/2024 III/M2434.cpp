#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> colouring(int n, int m){
  srand(time(NULL));
  set<vector<int>> used;
  vector<vector<int>> arr(n, vector<int>(m, -1));
  int dx[4] = {0, 0, 1, 1};
  int dy[4] = {0, 1, 0, 1};
  for (int i=0; i<n-1; i++) {
    for (int j=0; j<m-1; j++) {
      vector<pair<int, int>> ca;
      for (int k=0; k<4; k++) if (arr[i+dx[k]][j+dy[k]]==-1) ca.push_back({i+dx[k], j+dy[k]});
      int loops = 100;
      while (loops--) {
        for (auto v:ca) arr[v.first][v.second] = rand() % 16;
        vector<int> na;
        for (int k=0; k<4; k++) na.push_back(arr[i+dx[k]][j+dy[k]]);
        if (!used.count(na)) {
          used.insert(na);
          break;
        }
      }
      if (loops==0) return colouring(n, m);
    }
  }
  return arr;
}

void solve() {
    freopen ("color.out", "w", stdout);
    vector<vector<int>> ans = colouring(257, 257);
    for (int i=0; i<257; i++) {
        for (int j=0; j<257; j++) cout << ans[i][j] << " ";
        cout << "\n";
    }
    freopen("/dev/tty", "w", stdout);
    cout << "Accepted";
}

int main(){
    solve();    
}