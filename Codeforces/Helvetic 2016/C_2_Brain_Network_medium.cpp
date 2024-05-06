#include <bits/stdc++.h>
using namespace std;
bool visited[100005];
vector<int> graph[100005];
int md = 0, mdind = 0;
void dfs(int n, int d) {
    visited[n] = true;
    if (d>md) md = d, mdind = n;
    for (auto adj:graph[n]) if (!visited[adj]) dfs(adj, d+1);
}

int main(){
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1, 0);
    for (int i=1; i<=n; i++) visited[i] = false;
    dfs(mdind, 0);
    cout << md;
}

// Find diameter of tree