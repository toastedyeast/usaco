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
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    int K, N; cin >> K >> N;
    int order[K][N];
    for (int i=0; i<K; i++) {
        for (int j=0; j<N; j++) {
            cin >> order[i][j];
        }
    }
    map<pair<int, int>, int> tracker;
    for (int i=0; i<K; i++) {
        for (int j=0; j<N-1; j++) {
            for (int k=j+1; k<N; k++) {
                if (!tracker[make_pair(order[i][j], order[i][k])]) {
                    tracker[make_pair(order[i][j], order[i][k])] = 1;
                } else {
                    tracker[make_pair(order[i][j], order[i][k])]++;
                }
            }
        }
    }
    int counter = 0;
    for (auto pair: tracker) {
        if (pair.second == K) {
            counter++;
        }
    }
    cout << counter;
}