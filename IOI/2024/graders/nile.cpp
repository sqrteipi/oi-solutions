#include "nile.h"
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
vector<long long> calculate_costs(vector<signed> W, vector<signed> A,
                                       vector<signed> B, vector<signed> E) {
    int n = W.size(), sum = 0;
    for (int i=0; i<n; i++) {
        sum += B[i];
        A[i] -= B[i];
    }
    vector<pii> arr(n);
    for (int i=0; i<n; i++) arr[i] = {W[i], A[i]};
    sort(arr.begin(), arr.end());
    vector<int> ans;
    for (auto var : E) {
        int cost = sum;
        for (int l=0; l<n; ) {
            int r = l;
            while (r < n - 1 && arr[r].first + var >= arr[r + 1].first) r++;
            if ((r - l + 1) % 2 == 1) {
                int mn = 1e18;
                for (int i=l; i<=r; i++) {
                    if ((i - l + 1) % 2 == 1) mn = min(mn, arr[i].second);
                    else if (arr[i-1].first + var >= arr[i+1].first) mn = min(mn, arr[i].second);
                }
                cost += mn;
            }
            l = r + 1;
        }
        ans.push_back(cost);
    }
    return ans;
}
