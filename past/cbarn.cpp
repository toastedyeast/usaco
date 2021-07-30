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
    freopen("cbarn.in", "r", stdin);
    freopen("cbarn.out", "w", stdout);
    int N; cin >> N; int data[N];
    for (int i=0; i<N; i++) {
        cin >> data[i];
    }
    int distances[N];
    for (int i=0; i<N; i++) {
        int distance = 0;
        for (int j=0; j<N; j++) {
            if (j >= i) {
                distance += data[j] * (j - i);
            } else {
                distance += data[j] * (N - i + j);
            }
        }
        distances[i] = distance;
    }
    int current_lowest = 2147483647;
    for (int i=0; i<N; i++) {
        if (distances[i] < current_lowest) current_lowest = distances[i];
    }
    cout << current_lowest;
}