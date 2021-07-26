#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
    freopen("breedflip.in", "r", stdin);
    freopen("breedflip.out", "w", stdout);

    int N; cin >> N;
    string A; cin >> A;
    string B; cin >> B;

    int flips = 0;
    if (A[0] != B[0]) {
        flips++;
    }

    for (int i=1; i<N; i++) {
        if (A[i] != B[i] && A[i - 1] == B[i - 1]) {
            flips++;
        }
    }
    cout << flips;
}
