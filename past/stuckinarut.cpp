#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;


int main() {
    int N; cin >> N;
    int cows[N][5];
    for (int i=0; i<N; i++) {
        char direction; cin >> direction;
        if (direction == 'E') {
            cows[i][0] = 0;
        } else {
            cows[i][0] = 1;
        }
        cin >> cows[i][1] >> cows[i][2];
        cows[i][3] = 0;
        cows[i][4] = 1;
    }
    int field[700][700] = {};
    for (int time = 0; time < 600; time++) {
        for (int i=0; i<N; i++) {
            if (cows[i][4] != 0) {
                if (field[cows[i][1]][cows[i][2]] != 0 && field[cows[i][1]][cows[i][2]] != time) {
                    cows[i][4] = 0;
                } else {
                    cows[i][3]++;
                    field[cows[i][1]][cows[i][2]] = time;
                    if (cows[i][0] == 0) {
                        cows[i][1]++;
                    } else {
                        cows[i][2]++;
                    }
                }
            }

        }
    }
    for (int i=0; i<N; i++) {
        if (cows[i][4] != 0) {
            cout << "Infinity" << endl;
        } else {
            cout << cows[i][3] << endl;
        }
    }
}
