#include <bits/stdc++.h>
using namespace std;
int main(){
    srand(time(NULL));
    freopen("sample.txt", "w", stdout);
    cout << "1000 12000 4\n";
    vector<int> order;
    for (int i=1; i<=1000; i++) order.push_back(i);
    random_shuffle(order.begin(), order.end());
    for (int i=0; i<999; i++) {
        cout << order[i] << " " << order[i+1] << " " << rand() % 1000000000 << "\n";
    }
}