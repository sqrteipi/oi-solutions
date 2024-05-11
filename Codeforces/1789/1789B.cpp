#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        vector<int> cnt={0};
        int k = n / 2, l=0, r=n-1;
        while (k--) {
            if (s[l]!=s[r]) cnt.back()++;
            else if (cnt.back()>0) cnt.push_back(0);
            l++; r--;
        }
        if (cnt.size()==1) cout << "Yes\n";
        else if (cnt.size()==2&&cnt.back()==0) cout << "Yes\n";
        else cout << "No\n";
    }
}