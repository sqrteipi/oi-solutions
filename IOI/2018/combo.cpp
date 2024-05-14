#include "combo.h"
#include <bits/stdc++.h>
using namespace std;
string guess_sequence(int N) {
  string p = "";
  if (N == 1) {
    if (press("AA")==1) p += "A";
    else if (press("BB")==1) p += "B";
    else if (press("XX")==1) p += "X";
    else p += "Y";
    return p;
  }
  else {
    if (press("ABAAXAYA")==1) p += "A";
    if (press("BABBXBYB")==1) p += "B";
    if (press("XAXXBXYX")==1) p += "X";
    if (p.size()==1) p += "Y";
    if (N==2) {
      if (press(p)!=2) swap(p[0], p[1]);
    }
    else {
      string s;
      
    }
    return p;
  }
}

/*
ABAAXAYA -> 1, Related to A, >= 2 not related to A
*/