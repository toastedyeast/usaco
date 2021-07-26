#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool check (const int compare[], int K);

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int K, N; cin >> K >> N;
    int cows[K][N];
    for (int i=0; i<K; i++) {
        for (int j=0; j<N; j++) {
            cin >> cows[i][j];
        }
    }

    int compare[K];
    int total = 0;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int l=0; l<K; l++) {
                if (cows[l][i] > cows[l][j]) compare[l] = 0;
                if (cows[l][i] < cows[l][j]) compare[l] = 1;
                if (cows[l][i] == cows[l][j]) compare[l] = 2;
            }

            if (check(compare, K)) total++;
        }
    }
    cout << total;
}

bool check (const int compare[], int K) {
    for (int i=0; i<K; i++) {
        if (compare[i] != 0) return false;
    }
    return true;
}
