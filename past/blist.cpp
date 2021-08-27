#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    int N; cin >> N;
    int cows[N][3];
    for (int i=0; i<N; i++) {
        cin >> cows[i][0] >> cows[i][1] >> cows[i][2];
    }
    int time[1000];
    for (int & i : time) {
        i = 0;
    }
    for (auto cow: cows) {
        for (int i=cow[0]; i<=cow[1]; i++) {
            time[i - 1] += cow[2];
        }
    }
    int output = 0;
    for (int & i : time) {
        output = max(output, i);
    }
    cout << output;
}
