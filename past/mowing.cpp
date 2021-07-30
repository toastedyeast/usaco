#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <array>
#include <iterator>
#include <tuple>

using namespace std;

int main() {
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);
    int N; cin >> N; vector<pair<char, int>> path;
    for (int i=0; i<N; i++) {
        char direction; int units;
        cin >> direction >> units;
        path.emplace_back(direction, units);
    }
    pair<int, int> position = make_pair(0, 0);
    map<pair<int, int>, int> tracker; tracker[position] = 0;
    int time = 0;
    int limit = 2147483647;
    for (auto move: path) {
        if (move.first == 'N') {
            int i=0;
            while (i<move.second) {
                time++;
                position.second++;
                if (!tracker[position]) {
                    tracker[position] = time;
                } else {
                    if (time - tracker[position] < limit) {
                        limit = time - tracker[position];
                    }
                }
                i++;
            }
        } else if (move.first == 'S') {
            int i=0;
            while (i<move.second) {
                time++;
                position.second--;
                if (!tracker[position]) {
                    tracker[position] = time;
                } else {
                    if (time - tracker[position] < limit) {
                        limit = time - tracker[position];
                    }
                }
                i++;
            }
        } else if (move.first == 'E') {
            int i=0;
            while (i<move.second) {
                time++;
                position.first++;
                if (!tracker[position]) {
                    tracker[position] = time;
                } else {
                    if (time - tracker[position] < limit) {
                        limit = time - tracker[position];
                    }
                }
                i++;
            }
        } else {
            int i=0;
            while (i<move.second) {
                time++;
                position.first--;
                if (!tracker[position]) {
                    tracker[position] = time;
                } else {
                    if (time - tracker[position] < limit) {
                        limit = time - tracker[position];
                    }
                };
                i++;
            }
        }
    }
    if (limit == 2147483647) {
        cout << -1;
        return 0;
    }
    cout << limit;
}