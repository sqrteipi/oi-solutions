#include <bits/stdc++.h>
using namespace std;
int main(){
    int v1, v2, v3, v4;
    cin >> v1 >> v2 >> v3 >> v4;
    if (v1!=v2&&v1!=v4&&v2!=v4&&v2==v3) cout << "Yes";
    else cout << "No";
}