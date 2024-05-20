#include <bits/stdc++.h>
using namespace std;
int main(){
    string s="222355555";
    while (true) {
        int n = stoi(s);
        bool ok = true;
        for (int i=2; i*i<=n; i++) if (n%i==0) {
            ok = false;
            break;
        }
        if (ok) cout << s << "\n";
        if (!next_permutation(s.begin(), s.end())) break;
    }
}