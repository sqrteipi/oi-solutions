#include "toxic.h"
#include <bits/stdc++.h>
using namespace std;

int toxic;

void determine_type(int n){
	int l = 1, r = n;
	while (l<r) {
		int mid = (l+r)/2;
		vector<int> v;
		for (int i=l; i<=mid; i++) v.push_back(i);
		int qr = query_sample(v);
		if (qr==mid-l+1) l = mid + 1;
		else r = mid - 1;
	}
	toxic = l;
	cout << toxic << " ";
	answer_type(l,'T');	
	for (int i=1; i<=n; i++) {
		int qr = query_sample({l, i});
		if (qr==0) answer_type(i, 'T'), cout << i << " T\n";
		else if (qr==1) answer_type(i, 'S') , cout << i << " S\n";
		else answer_type(i, 'R'), cout << i << " R\n";
	}
}