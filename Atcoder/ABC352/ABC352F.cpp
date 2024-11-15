/*
User : sqrteipi
Tags: Brute force, Graph, DFS
Rating: 2052
*/

#include <bits/stdc++.h>
using namespace std;

int n, m;

// Find sets
bool visited[20];
vector<vector<int>> sets;
vector<int> singles;

int sum[20], used[20], ans[20];
vector<int> order;
set<int> pos_ans[20], pos_singles;

void solve() {
  int k1 = sets.size(), k2 = order.size(), k3 = singles.size();
  if (k1==k2) {
    for (int i=0; i<k2; i++) pos_ans[i].insert(order[i]);
    if (k3==1) for (int i=1; i<=n; i++) if (!used[i]) pos_singles.insert(i);
    return;
  }
  vector<int> curset = sets[k2];
  for (int pos=1; pos<=n; pos++) {
    if (!used[pos]) {
      bool ok = true;
      vector<int> occupy;
      for (auto var:curset) occupy.push_back(pos+sum[var]);
      for (auto var:occupy) if (var<1||var>n||used[var]) ok = false;
      if (!ok) continue;
      order.push_back(pos);
      for (auto var:occupy) used[var] = true;
      solve();
      for (auto var:occupy) used[var] = false;
      order.pop_back();
    }
  }
}

int main(){
  cin >> n >> m;

  // Graph Setup
  vector<pair<int, int>> graph[n+1];
  for (int i=0; i<m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, -w}); // Reverse Direction = Reverse Cost
    graph[v].push_back({u,  w});
  }

  // Group sets
  for (int i=1; i<=n; i++) if (!visited[i]) {
    vector<int> curset; // Set for the current root 
    queue<int> q;
    q.push(i); // Start from root
    while (!q.empty()) { // BFS
      int u = q.front();
      if (!visited[u]) {
        visited[u] = true;
        curset.push_back(u);
        for (auto adj:graph[u]) {
          int v = adj.first, w = adj.second;
          sum[v] = sum[u] + w;
          q.push(v);
        }
      }
      q.pop();
    }
    if (curset.size()>1) sets.push_back(curset);
    else singles.push_back(curset[0]);
  }
  solve();

  int k = sets.size();
  for (int i=0; i<k; i++) {
    vector<int> curset = sets[i];
    if (pos_ans[i].size()>1) for (auto var:curset) ans[var] = -1;
    else for (auto var:curset) ans[var] = (*pos_ans[i].begin()) + sum[var];
  }
  if (singles.size()>1||pos_singles.size()>1) for (auto var:singles) ans[var] = -1;
  else if (!singles.empty()) ans[singles[0]] = (*pos_singles.begin());
  for (int i=1; i<=n; i++) cout << ans[i] << " ";
}
