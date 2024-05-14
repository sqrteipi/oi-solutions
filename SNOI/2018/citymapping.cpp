#include "citymapping.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void find_roads(int N, int Q, int A[], int B[], int W[]) {
	if (Q==500000) {
		
	}
    else {
		// Task 3 and 4: Search for deepest node (highest weight), and search from the node
		ll dis=0, deep=0;
		for (int i=2; i<=N; i++) {
			ll curdis = get_distance(1, i);
			if (curdis>dis) dis = curdis, deep = i;
		}
		vector<pair<ll, ll>> arr;
		for (int i=1; i<=N; i++) {
			if (deep==i) continue;
			ll curdis = get_distance(i, deep);
			arr.push_back({curdis, i});
		}
		sort(arr.begin(), arr.end());
		int prev = deep;
		for (int i=0; i<N-1; i++) {
			A[i] = prev; B[i] = arr[i].second;
			if (i==0) W[i] = arr[i].first;
			else W[i] = (long long) arr[i].first-arr[i-1].first;
			prev = arr[i].second;
		}
		return;
	}
}
