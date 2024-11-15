#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    sort(a, a+n);
    deque<int> dq;
    for (int i=0; i<n; i++) dq.push_back(a[i]);
    int cnt = 0;
    while (!dq.empty()) {
        if (dq.size() == 1) dq.pop_front();
        else if (dq.front() + dq.back() <= m) dq.pop_front(), dq.pop_back();
        else dq.pop_back();
        cnt++;
    }
    cout << cnt;
}