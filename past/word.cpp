#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    int N, K; cin >> N >> K;
    string sentence[N];
    for (int i=0; i<N; i++) {
        cin >> sentence[i];
    }
    int temp = sentence[0].length();
    cout << sentence[0];
    for (int i=1; i<N; i++) {
        if (temp + sentence[i].length() <= K) {
            temp += sentence[i].length();
            cout << " " << sentence[i];
        } else {
            cout << "\n" << sentence[i];
            temp = sentence[i].length();
        }
    }


}
