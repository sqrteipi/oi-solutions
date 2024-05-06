#include <bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int> graph[1005];
int main(){
    int n, m;
    cin >> n >> m;
    if (m!=n-1) cout << "no";
    else {
        while (m--) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        queue<int> q;
        q.push(1);
        while (!q.empty()) {
            if (!visited[q.front()]) {
                visited[q.front()] = true;
                for (auto adj:graph[q.front()]) q.push(adj);
            }
            q.pop();
        }
        for (int i=1; i<=n; i++) if (!visited[i]) {
            cout << "no";
            return 0;
        }
        cout << "yes";
    }
}

// Check if the given graph is a tree