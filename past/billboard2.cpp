#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <iterator>
#include <tuple>

using namespace std;

int main() {
    freopen("billboard.in", "r", stdin);
    freopen("billboard.out", "w", stdout);
    int loc[2][4];
    for (auto & i : loc) {
        for (int & j : i) {
            cin >> j;
        }
    }
    set<tuple<int, int>> coords;
    for (int x=loc[0][0]; x<loc[0][2]; x++) {
        for (int y=loc[0][1]; y<loc[0][3]; y++) {
            coords.insert(make_tuple(x, y));
        }
    }
    for (int x=loc[1][0]; x<loc[1][2]; x++) {
        for (int y=loc[1][1]; y<loc[1][3]; y++) {
            if (coords.count(make_tuple(x, y)) == 1) {
                coords.erase(make_tuple(x, y));
            }
        }
    }
    if (coords.empty()) {
        cout << 0;
    } else {
        int min_x = 1000;
        int min_y = 1000;
        int max_x = -1000;
        int max_y = -1000;
        for (auto tup: coords) {
            int x = get<0>(tup);
            int y = get<1>(tup);
            if (x < min_x) min_x = x;
            if (y < min_y) min_y = y;
            if (x > max_x) max_x = x;
            if (y > max_y) max_y = y;
        }
        cout << (max_x + 1 - min_x) * (max_y + 1 - min_y);
    }
}