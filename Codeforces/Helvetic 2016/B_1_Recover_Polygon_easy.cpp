#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> ones;
int twocnt=0, fourcnt=0;
char grid[55][55], grid2[55][55];
int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        cin >> grid[i][j];
        if (grid[i][j]=='1') ones.push_back({i, j});
    }
    if (ones.size()!=4) cout << "No";
    else {
        pair<int, int> v1 = ones[0], v4 = ones[3], v2 = {v1.first, v4.second}, v3 = {v4.first, v1.second};
        if (ones[1]!=v2||ones[2]!=v3) cout << "No";
        else {
            for (int i=0; i<n; i++) for (int j=0; j<n; j++) grid2[i][j] = '0';
            for (int i=v1.first; i<=v4.first; i++) for (int j=v1.second; j<=v4.second; j++) {
                pair<int, int> loc = {i, j};
                if (i>v1.first&&i<v4.first&&j>v1.second&&j<v4.second) grid2[i][j] = '4';
                else if (loc!=v1&&loc!=v2&&loc!=v3&&loc!=v4) grid2[i][j] = '2';
                else grid2[i][j] = '1';
            }
            bool ok = true;
            for (int i=0; i<n; i++) for (int j=0; j<n; j++) if (grid[i][j]!=grid2[i][j]) ok = false;
            if (ok) cout << "Yes";
            else cout << "No";
        }
    }
}

/*
A rectangle will form the following pattern:
1 2 ... 2 1
2 4 ... 4 2
.    .    . 
.   ...   .
.    .    .
2 4 ... 4 2
1 2 ... 2 1
*/