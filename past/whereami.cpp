#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    int N; cin >> N;
    string text; cin >> text;

    for (int i=1; i<=N; i++) {
        bool unique = true;
        for (int j=0; j + i <= N; j++) {
            for (int k=0; k + i <= N; k++) {
                if (text.substr(j, i) == text.substr(k, i) && k != j) {
                    unique = false;
                }
            }
        }
        if (unique) {
            cout << i;
            break;
        }
    }
}