#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    cout << (n + 1) / 2;
}

/*
Brainstorm:

If n = 1, obviously 1
If n = 2, still 1 (since always win vote)
If n = 3, requires 2:
The 3rd people obviously know he will get no brain if N = 2
Therefore you need to give 1 to the 3rd people to support with you

From now on, discuss on the best distribution
n = 1: 1
n = 2: 1 0
n = 3: 1 0 1
n = 4: 1 0 1 0
n = 5: 1 0 1 0 1
...
Therefore, the no. of heads is ceil (n / 2). 
*/