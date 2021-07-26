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
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
    int N; cin >> N;
    map <int, pair<bool, int>> times;
    for (int i=0; i<1000; i++) {
        times[i].first = false;
        times[i].second = 0;
    }
    int shifts[N][2];
    for (int i=0; i<N; i++) {
        int start; int end;
        cin >> start >> end;
        shifts[i][0] = start; shifts[i][1] = end;
        for (int j=start; j<end; j++) {
            times[j].first = true;
            times[j].second++;
        }
    }
    int highest_output = 0;
    for (int i=0; i<N; i++) {
        int start = shifts[i][0]; int end = shifts[i][1];
        for (int j=start; j<end; j++) {
            if (times[j].second < 2) {
                times[j].first = false;
            }
        }
        int output=0;
        for (int k=0; k<1000; k++) {
            if (times[k].first) {
                output++;
            }
        }
        if (output > highest_output) {
            highest_output = output;
            for (int l=start; l<end; l++) {
                times[l].first = true;
            }
        } else {
            for (int l=start; l<end; l++) {
                times[l].first = true;
            }
        }
    }
    cout << highest_output;
}