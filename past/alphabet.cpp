#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string alphabet; cin >> alphabet;
    string word; cin >> word;
    int i = 0;
    int sung = 0;
    while (i < word.length()) {
        for (int j=0; j<alphabet.length(); j++) {
            if (word[i] == alphabet[j]) {
                i++;
            }
            if (j == alphabet.length() - 1) {
                sung++;
                j == 0;
            }
        }
    }
    cout << sung;
}
