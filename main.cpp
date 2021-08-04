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
    freopen("socdist2.in", "r", stdin);
    freopen("socdist2.out", "w", stdout);
    int N; cin >> N;
    vector<int> healthy; vector<int> sick;
    for (int i=0; i<N; i++) {
        int pos, infected;
        cin >> pos >> infected;
        if (infected == 0) {
            healthy.push_back(pos);
        } else {
            sick.push_back(pos);
        }
    }
    if (healthy.empty()) {
        cout << 1;
        return 0;
    }
    int max_R = 2^31-1;
    for (auto cow: sick) {
        int closest = 2^31-1;
        for (auto heal: healthy) {
            if (abs(heal - cow) < closest) closest = abs(heal - cow);
        }
        if (closest < max_R) max_R = closest;
    }
    max_R = max_R - 1;
    int counter = 0;
    sort(sick.begin(), sick.end());
//    for (int i=0; i<sick.size(); i++) {
//        contaminated[sick[i]] = true;
//        if (i != sick.size() - 1) {
//            if (sick[i] + max_R > sick[i + 1]) {
//                continue;
//            } else {
//                counter++;
//            }
//        }
//    }
    for (int i=0; i<sick.size(); i++) {
        if (i==0 || sick[i - 1] + max_R < sick[i]) {
            counter++;
        }
    }
    cout << counter;
}

