#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int a[n], b[n];
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    vector<int> op;
    int lst = -1;
    for (int i=n-1; i>=0; i--) {
        if (lst > a[i] || b[i] > a[i]) {
            cout << "Impossible";
            return 0;
        }
        if (a[i] > b[i]) op.push_back(a[i] - b[i]);
        lst = max(lst, b[i]);
    }
    cout << op.size() << "\n";
    for (auto var : op) cout << var << "\n";
}