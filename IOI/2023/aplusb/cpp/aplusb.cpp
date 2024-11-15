#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
 
vector<int> smallest_sums(int n, vector<int> a, vector<int> b) {
  sort(b.begin(), b.end());
  int ptr[n], p=0;
  vector<int> ans;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  for (int i=0; i<n; i++) pq.push({a[i] + b[0], i});
  for (int i=0; i<n; i++) ptr[i] = 1;
  while (!pq.empty()) {
    if (ans.size() == n) break;
    ans.push_back(pq.top().first);
    int ind = pq.top().second; 
    pq.pop();
    if (ptr[ind] == n) continue;
    pq.push({a[ind] + b[ptr[ind]], ind});
    ptr[ind]++;
  }
  return ans;
}