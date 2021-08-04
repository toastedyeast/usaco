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
//    freopen("socdist1.in", "r", stdin);
//    freopen("socdist1.out", "w", stdout);
    int N; cin >> N;
    string stalls; cin >> stalls;
    vector<int> distances;
    int prev = -1;
    for (int i=0; i<N; i++) {
        if (stalls[i] == '1') {
            if (prev == -1) {
                prev = i;
            } else {
                distances.push_back(i - prev);
                prev = i;
            }
        }
    }
    if (distances.empty()) {
        if (prev == -1) {
            cout << N - 1;
            return 0;
        } else {
            cout << N - 2;
            return 0;
        }
    }
    pair<int, int>highest_distance = {0, 0};
    for (int i=0; i<distances.size(); i++) {
        if (distances[i] > highest_distance.first) {
            highest_distance.first = distances[i];
            highest_distance.second = i;
        }
    }
    distances.erase(distances.begin() + highest_distance.second);
    if (highest_distance.first % 2 == 0) {
        distances.push_back(highest_distance.first / 2);
        distances.push_back(highest_distance.first / 2);
    } else {
        int first = static_cast<int>(highest_distance.first / 2 + 0.5);
        int second = highest_distance.first - first;
        distances.push_back(first);
        distances.push_back(second);
    }
    pair<int, int>highest_distance2 = {0, 0};
    for (int i=0; i<distances.size(); i++) {
        if (distances[i] > highest_distance2.first) {
            highest_distance2.first = distances[i];
            highest_distance2.second = i;
        }
    }
    distances.erase(distances.begin() + highest_distance2.second);
    if (highest_distance2.first % 2 == 0) {
        distances.push_back(highest_distance2.first / 2);
        distances.push_back(highest_distance2.first / 2);
    } else {
        int first = static_cast<int>(highest_distance2.first / 2 + 0.5);
        int second = highest_distance2.first - first;
        distances.push_back(first);
        distances.push_back(second);
    }
    int output = 2147483647;
    for (auto distance: distances) {
        if (distance < output) {
            output = distance;
        }
    }
    if (floor(highest_distance.first / 3) > output) {
        cout << floor(highest_distance.first / 3);
        return 0;
    }
    cout << output << endl;
}

