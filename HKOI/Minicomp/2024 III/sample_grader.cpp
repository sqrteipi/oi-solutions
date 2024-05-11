#include <bits/stdc++.h>
using namespace std;

set<vector<int>> used;
vector<vector<int>> arr(257, (vector<int>(257, -1)));
int dx[4] = {0, 0, 1, 1};
int dy[4] = {0, 1, 0, 1};

vector<vector<int>> colouring(int n, int m){
  ofstream ou ("color.out");
  srand(time(NULL));
  used = {{}};
  for (int i=0; i<n; i++) for (int j=0; j<m; j++) arr[i][j] = -1;
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

  for (int i=0; i<n; i++) {
    for (int j=0; j<m; j++) ou << arr[i][j] << " ";
    ou << "\n";
  }
  
  return arr;
}

static int N, M;
static std::vector<std::vector<int>> reported;

double get_score(int C){
    if (C <= 16) return 100;
    else if (C <= 32) return 55 + 2.0 * (32 - C);
    else if (C <= 256) return 15 + 40.0 * 32 / C;
    else if (C <= 66049) return 5 + 15.0 * 256 / C;
    else return 0;
}

int main() {
    while (true) {
        int N = 257, M = 257;

        reported = colouring(N, M);

        if (reported.size() != N) {
            printf("Incorrect. The size of the colouring is not N x M.\n");
            return 0;
        }
        for (int i = 0; i < N; i++) {
            if (reported[i].size() != M) {
                printf("Incorrect. The size of the colouring is not N x M.\n");
                return 0;
            }
        }
        
        vector a = reported;
        
        set<vector<int>> S;
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                vector<int> v;
                for (int x = 0; x < 2; x++) {
                    for (int y = 0; y < 2; y++) {
                        v.push_back(a[i + x][j + y]);
                    }
                }
                S.insert(v);
            }
        }

        // for (int i = 0; i < N; i++) {
        //     for (int j = 0; j < M; j++) {
        //         cout << a[i][j] << " \n"[j == M - 1];
        //     }
        // }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (a[i][j] < 0 || a[i][j] > 1'000'000'000) {
                    printf("Incorrect. Colour at block (%d, %d) out of bound\n", i, j);
                    return 0;
                }
            }
        }

        set<int> colours;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                colours.insert(a[i][j]);
            }
        }
        int C = colours.size();

        if (S.size() != (N - 1) * (M - 1)) {
            printf("Incorrect. Colours of some 2x2 blocks are repeated. Size: %d\n", S.size());
            return 0;
        }

        printf("Correct. Used %d colours, score = %.3lf\n", C, get_score(C));
    }
}
