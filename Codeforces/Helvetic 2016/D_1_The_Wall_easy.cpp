#include <bits/stdc++.h>
using namespace std;
bool visited[100][100];
int main(){
    int n, m, cnt=0;
    cin >> n >> m;
    char grid[n][m];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin >> grid[i][j];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if(!visited[i][j]&&grid[i][j]=='B') {
        cnt++;
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            if (x>=0&&x<n&&y>=0&&y<m&&grid[x][y]=='B'&&!visited[x][y]) {
                visited[x][y] = true;
                q.push({x-1, y});
                q.push({x+1, y});
                q.push({x, y-1});
                q.push({x, y+1});
            } 
            q.pop();
        }
    }
    cout << cnt;
}