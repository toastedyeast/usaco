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
#include <unordered_map>

using namespace std;

int main() {
    freopen("revegetate.in", "r", stdin);
    freopen("revegetate.out", "w", stdout);
    int N, M; cin >> N >> M;
    vector<pair<int, int>> favorites;
    for (int i=0; i<M; i++) {
        int first, second; cin >> first >> second;
        favorites.emplace_back(first, second);
    }
    int pastures[N];
    for (int i=0; i<N; i++) {
        if (i == 0) {
            pastures[i] = 1;
        } else {
            map<int, bool> forbidden;
            forbidden[1] =false; forbidden[2] = false; forbidden[3] = false; forbidden[4] = false;
            for (int j=0; j<i; j++) {
                for (auto pair: favorites) {
                    if (pair == make_pair(i+1, j+1) || pair == make_pair(j+1, i+1)) {
                        forbidden[pastures[j]] = true;
                    }
                }
            }
            for (int k=1; k<5; k++) {
                if (!forbidden[k]) {
                    pastures[i] = k;
                    break;
                }
            }
        }
    }
    for (auto pasture: pastures) {
        cout << pasture;
    }
}

