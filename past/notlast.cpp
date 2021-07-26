#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    freopen("notlast.in", "r", stdin);
    freopen("notlast.out", "w", stdout);
    int N; cin >> N; map <string, int> data;
    for (int i=0; i<N; i++) {
        string cow; int milk;
        cin >> cow >> milk;
        if (data.count(cow) == 0) {
            data[cow] = milk;
        } else {
            data[cow] += milk;
        }
    }
    int current_lowest=100000; int current_second=100000; string output;
    for (auto& cow: data) {
        if (cow.second < current_lowest) {
            current_lowest = cow.second;
        }
    }
    if (data.size() != 7) {
        current_lowest = 0;
    }
    for (auto& cow: data) {
        if (cow.second < current_second && cow.second > current_lowest) {
            current_second = cow.second;
            output = cow.first;
        }
    }
    int tie_counter = 0;
    for (auto& cow:data) {
        if (cow.second == current_second) tie_counter++;
    }
    if (tie_counter == 1) {
        cout << output;
    } else {
        cout << "Tie";
    }
}