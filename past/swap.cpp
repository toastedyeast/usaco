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


//void reverse(int first, int second) {
//    if (second - first % 2 == 0) {
//        for (int i=0; i<(second - first)/2; i++) {
//            int tmp = cows[second-i-1];
//            cows[second-i-1] = cows[first+i-1];
//            cows[first+i-1] = tmp;
//        }
//    } else {
//        for (int i=0; i<int((second - first) / 2 + 0.5); i++) {
//            int tmp = cows[second-i-1];
//            cows[second-i-1] = cows[first+i-1];
//            cows[first+i-1] = tmp;
//        }
//    }
//}


int main() {
//    freopen("revegetate.in", "r", stdin);
//    freopen("revegetate.out", "w", stdout);
    int N, K; cin >> N >> K; int cows[101];
    int a1, a2, b1, b2; cin >> a1 >> a2 >> b1 >> b2;
    for (int i=0; i<N; i++) {
        cows[i] = i+1;
    }
    for (int j=0; j<K; j++) {
        int first = a1; int second = a2;
        if (second - first % 2 == 0) {
            for (int i=0; i<(second - first)/2; i++) {
                int tmp = cows[second-i-1];
                cows[second-i-1] = cows[first+i-1];
                cows[first+i-1] = tmp;
            }
        } else {
            for (int i=0; i<int((second - first) / 2 + 0.5); i++) {
                int tmp = cows[second-i-1];
                cows[second-i-1] = cows[first+i-1];
                cows[first+i-1] = tmp;
            }
        }
        first = b1; second = b2;
        if (second - first % 2 == 0) {
            for (int i=0; i<(second - first)/2; i++) {
                int tmp = cows[second-i-1];
                cows[second-i-1] = cows[first+i-1];
                cows[first+i-1] = tmp;
            }
        } else {
            for (int i=0; i<int((second - first) / 2 + 0.5); i++) {
                int tmp = cows[second-i-1];
                cows[second-i-1] = cows[first+i-1];
                cows[first+i-1] = tmp;
            }
        }
    }
    for (int i=0; i<N; i++) {
        cout << cows[i] << endl;
    }
}


