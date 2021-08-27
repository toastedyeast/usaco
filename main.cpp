#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;


int main() {
    int N; cin >> N;
    vector<int> cows; vector<int> stalls;
    for (int i=0; i<N; i++) {
        int height;
        cin >> height;
        cows.push_back(height);
    }
    for (int i=0; i<N; i++) {
        int height;
        cin >> height;
        stalls.push_back(height);
    }
    long long output = 1;
    sort(cows.begin(), cows.end());
    for (int i=N-1; i>0; i--) {
        if (i == N - 1) {
            int counter = 0;
            for (int j=0; j<N; j++) {
                if (stalls[j] >= cows[i]) {
                    counter++;
                }
            }
            output *= counter;
        } else {
            int counter = 0;
            for (int j=0; j<N; j++) {
                if (stalls[j] >= cows[i]) {
                    counter++;
                }
            }
            counter -= N - 1 - i;
            output *= counter;
        }
    }
    cout << output;
}
