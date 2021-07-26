#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);

    int N; cin >> N;
    int b[N-1];
    for (int i=0; i<N - 1; i++) {
        cin >> b[i];
    }

    int next;
    vector<int> nexts;
    for (int guess=1; guess<b[0]; guess++) {
        if (N == nexts.size()) {
            break;
        }
        nexts.clear();
        next = guess;
        for (int i=0; i<N; i++) {
            nexts.push_back(next);
            if (b[i] - next > 0) {
                if (find(nexts.begin(), nexts.end(), b[i] - next) != nexts.end()) {
                    break;
                } else {
                    next = b[i] - next;
                }
            } else {
                break;
            }
        }
    }
    for (int i=0; i<N; i++) {
        cout << nexts[i];
        if (i < N - 1) {
            cout << " ";
        }
    }
}
