#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    int a[2], b[2], c[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1] >> c[0] >> c[1];
    int turn = 0;
    for (int i=0; i<100; i++) {
        if (turn == 0) {
            while (b[1] < b[0] && a[1] > 0) {
                a[1]--; b[1]++;
            }
            turn++;
        }
        else if (turn==1){
            while(c[1] < c[0] && b[1] > 0) {
                b[1]--;c[1]++;
            }
            turn++;
        }
        else if (turn==2) {
            while(a[1]<a[0] && c[1] > 0) {
                c[1]--;a[1]++;
            }
            turn = 0;
        }
    }
    cout << a[1] << endl << b[1] << endl << c[1];
}
