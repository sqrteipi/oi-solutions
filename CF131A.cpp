#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i=1; i<s.length(); i++) {
    if (!('A'<=s[i]&&s[i]<='Z')) {
      cout << s;
      return 0;
    }
  }
  for (int i=0; i<s.length(); i++) {
    char c=s[i];
    if ('A'<=c&&c<='Z') c += 'a'-'A';
    else c += 'A'-'a';
    cout << c;
  }
}
