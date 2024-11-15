#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
string guess_sequence(int N) {
  bool turn = false;
  string s;
  for (int _=0; _<N; _++) {
    if (!turn) {
      int a = press(s + "A");
      int b = press(s + "B");
      int x = press(s + "X");
      int y = press(s + "Y");
      int m = s.length();
      if (a == m) s 
    }
  }
  return "A";
}