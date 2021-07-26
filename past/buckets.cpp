#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    string grid[10];
    for (auto & i : grid) {
        getline(cin, i);
    }
    int b_coord[2];
    int l_coord[2];
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            if (grid[i][j] == 'B') {
                b_coord[0] = i;
                b_coord[1] = j;
            } else if (grid[i][j] == 'L') {
                l_coord[0] = i;
                l_coord[1] = j;
            }
        }
    }
    cout << abs(b_coord[0] - l_coord[0]) + abs(b_coord[1] - l_coord[1]) - 1;
}
