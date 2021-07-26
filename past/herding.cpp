#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int closest (int pos[]) {
    if (abs(pos[2] - pos[1]) > abs(pos[0] - pos[1])) {
        return 0;
    } else return 2;
}

bool consecutive(int pos[]) {
    if (pos[1] == pos[0] + 1 && pos[2] == pos[1] + 1) return true;
    else return false;
}


int main() {
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);

    int pos[3]; cin >> pos[0] >> pos[1] >> pos[2];
    sort(begin(pos), end(pos));
    if (consecutive(pos)) {
        cout << 0 << endl;
    }
    else if (abs(pos[0] - pos[1]) == 2 || abs(pos[0] - pos[2]) == 2 || abs(pos[1] - pos[2]) == 2) {
        cout << 1 << endl;
    }
    else {
        cout << 2 << endl;
    }


    bool keep_going = true;
    int max_moves = 0;
    while (!consecutive(pos)) {
        if (closest(pos) == 2) {
            pos[2] = pos[1] - 1;
            sort(begin(pos), end(pos));
            max_moves++;
        } else {
            pos[0] = pos[1] + 1;
            sort(begin(pos), end(pos));
            max_moves++;
        }

    }
    cout << max_moves;
}
