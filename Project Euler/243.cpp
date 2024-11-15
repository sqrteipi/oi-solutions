#include <bits/stdc++.h>
using namespace std;
#define int long long
bool sieve[100];
int32_t main(){
    int n = 1;
    for (int i=2; i<100; i++) if (!sieve[i]) for (int j=i+i; j<100; j+=i) sieve[j] = true;
    vector<int> vec;
    for (int i=2; i<100; i++) if (!sieve[i]) {
        vec.push_back(i);
        if (n > 1e17) break;
        n *= i;
        if (i == 23) {
            for (int j=1; j<=29; j++) {
                n *= j;
                double phi = n;
                for (auto var : vec) phi *= (1 - 1.0 / var);
                int phii = phi;
                double rate = phi * 1.0 / (n - 1);
                cout << fixed << setprecision(20);
                cout << n << " " << rate << " " << phii * 94744 << " " << (n - 1) * 15499 << " " << phii << "\n";
                n /= j;
            }
        }
    }
}