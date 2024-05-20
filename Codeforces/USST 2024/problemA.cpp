#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> arr;
    for (int i=0; i<n; i++) {
        int v;
        cin >> v;
        arr.push_back({v, i});
    }
    sort(arr.begin(), arr.end());
    for (auto p:arr) cout << p.second+1 << " ";
}