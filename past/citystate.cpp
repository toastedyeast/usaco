#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    freopen("citystate.in", "r", stdin);
    freopen("citystate.out", "w", stdout);
    int N; cin >> N; string cities[N][2];
    for (int i=0; i<N; i++) {
        cin >> cities[i][0] >> cities[i][1];
    }
    int counter = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            if (cities[i][0][0] == cities[j][1][0] && cities[i][0][1] == cities[j][1][1]) {
                if (cities[i][1][0] == cities[j][0][0] && cities[i][1][1] == cities[j][0][1]) {
                    counter++;
                }
            }
        }
    }
    cout << counter;
}