#include "citymapping.h"
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void find_roads(int N, int Q, int A[], int B[], int W[]) {
	// Task 3 and 4: Search for deepest node (highest weight), and search from the node
	ll dis=0, deep=0;
	for (int i=2; i<=N; i++) {
		ll curdis = get_distance(1, i);
		if (curdis>dis) dis = curdis, deep = i;
	}
	vector<pair<ll, ll>> arr;
}
