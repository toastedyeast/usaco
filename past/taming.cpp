#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <array>
#include <iterator>

using namespace std;

int main() {
    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);
    int N; cin >> N; int log[N];
    for (int i=0; i<N; i++) {
        cin >> log[i];
    }

    for (int i=N-1; i>0; i--) {
        if (log[i] != -1 && log[i] != 0 && log[i-1] == -1) {
            log[i-1] = log[i] - 1;
        }
    }
    int minimum[N]; copy(log, log + N, minimum); int min_counter = 1;
    for (int i=1; i<N; i++) {
        if (minimum[i] == 0) {
            min_counter++;
        }
    }
    int max_counter = 1;
    for (int i=1; i<N; i++) {
        if (log[i] == -1 || log[i] == 0) {
            max_counter++;
        }
    }
    cout << min_counter << " " << max_counter;
}