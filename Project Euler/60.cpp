#include <bits/stdc++.h>
using namespace std;
const int N = 5e7 + 10;
bool sieve[N] = {1, 1};

bool is_prime(int n) {
    for (int i=2; i*i<=n; i++) if (n % i == 0) return false;
    return true;
}

bool ok(int n, int m) {
    string s1 = to_string(n), s2 = to_string(m);
    int v1 = stoi(s1 + s2), v2 = stoi(s2 + s1);
    if (v1 < N && sieve[v1]) return false;
    if (v1 >= N && !is_prime(v1)) return false;
    if (v2 < N && sieve[v2]) return false;
    if (v2 >= N && !is_prime(v2)) return false;
    return true;
}

int main(){
    for (int i=0; i<N; i++) if (!sieve[i]) for (int j=i+i; j<N; j+=i) sieve[j] = true;
    int M = 10000;
    for (int i=0; i<M; i++) if (!sieve[i]) 
        for (int j=i+1; j<M; j++) if (!sieve[j] && ok(i, j)) 
            for (int k=j+1; k<M; k++) if (!sieve[k] && ok(i, k) && ok(j, k))
                for (int l=k+1; l<M; l++) if (!sieve[l] && ok(i, l) && ok(j, l) && ok(k, l))
                    for (int m=l+1; m<M; m++) if (!sieve[m] && ok(i, m) && ok(j, m) && ok(k, m) && ok(l, m))
                        cout << i << " " << j << " " << k << " " << l << " " << m << " " << i + j + k + l + m << "\n";
}