#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    int nums[n + 1], res = true, index = n - 1;
    for(int i = 0; i < n; i++) cin >> nums[i], nums[n] = -1;
    for(int i = 0; i < n; i++){
      while(nums[index] < i + 1) index--;
      if(index + 1!= nums[i]){res = false; break;}
    }
    if(res) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}
