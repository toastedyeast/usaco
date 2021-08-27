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
    int flowers[N];
    for (int i=0; i<N; i++) {
        cin >> flowers[i];
    }
    int counter = N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<i; j++) {
            int sum = 0;
            for (int k=j; k<=i; k++) {
                sum += flowers[k];
            }
            if (sum % (i - j + 1) != 0) {
                continue;
            } else {
                sum = sum / (i - j + 1);
            }
            for (int k=j; k<=i; k++) {
                if (flowers[k] == sum) {
                    counter++;
                    break;
                }
            }
        }
    }
    cout << counter;
}
