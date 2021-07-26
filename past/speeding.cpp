#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    int N, M; cin >> N >> M;
    int road[N][3]; int cow[M][3];
    for (int i=0; i<N; i++) {
        cin >> road[i][0] >> road[i][1];
        road[i][2] = 0;
    }
    for (int i=0; i<M; i++) {
        cin >> cow[i][0] >> cow[i][1];
        cow[i][2] = 0;
    }
    int highest_speeding = 0; int road_counter = 0; int cow_counter = 0;

    for (int i=1; i<101; i++) {
        if (road[road_counter][0] == road[road_counter][2]) {
            road_counter++;
        }
        if (cow[cow_counter][0] == cow[cow_counter][2]) {
            cow_counter++;
        }
        if (cow[cow_counter][1] > road[road_counter][1] && cow[cow_counter][1] - road[road_counter][1] > highest_speeding) {
            highest_speeding = cow[cow_counter][1] - road[road_counter][1];
        }
        road[road_counter][2]++; cow[cow_counter][2]++;
    }
    cout << highest_speeding;
}
