#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;


int main() {
    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);
    int N; cin >> N;
    int shuffle[N];
    for (int i=0; i<N; i++) {
        cin >> shuffle[i];
    }
    string order[N];
    for (int i=0; i<N; i++) {
        cin >> order[i];
    }
    for (int i=0; i<3; i++) {
        string temp[N];
        for (int j=0; j<N; j++) {
            temp[j] = order[shuffle[j] - 1];
        }
        for (int k=0; k<N; k++) {
            order[k] = temp[k];
        }
    }
    for (auto cow: order) {
        cout << cow << endl;
    }
}
