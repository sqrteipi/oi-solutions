#include "choreography.h"
#include <bits/stdc++.h>
using namespace std;

vector<int> vec, pos(100005);
int sum = 0, n;
void init(int N, vector<int> P) {
    n = N;
    vec = P;
    for (int i=0; i<n; i++) pos[vec[i]] = i;
} 

void move_right(int K) {
    sum = (sum + K) % n;
}

void move_left(int K) {
    sum = (sum - K) % n;
    return;
}

void swap_places() {
    return;
}

void move_around() {
    return;
}

int get_position(int D){
    return (pos[D] + sum + n) % n;
}
