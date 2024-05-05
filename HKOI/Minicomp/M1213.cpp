#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, c, n, k, cnt=0;
  cin >> r >> c >> n >> k;
  multiset<pair<int, int>> start_time;
  while (n--) {
    int r, x, y;
    cin >> r >> x >> y;
    start_time.insert({x, y});
  }
  multiset<int> end_time;
  while (!start_time.empty()) {
    int v = (*start_time.begin()).first;
    while (!end_time.empty()&&(*end_time.begin())<v) end_time.erase(end_time.begin());
    while (!start_time.empty()&&(*start_time.begin()).first==v) {
      end_time.insert((*start_time.begin()).second);
      start_time.erase(start_time.begin());
    }
    int l = max(0, (int) (end_time.size())-k);
    cnt += l;
    while (l--) end_time.erase(--end_time.end());
  }
  cout << cnt;
}
