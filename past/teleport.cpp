#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("teleport.in", "r", stdin);
    // the following line creates/overwrites the output file
    freopen("teleport.out", "w", stdout);
    // cin reads from the file instead of standard input
    int a, b, x, y; cin >> a >> b >> x >> y;
    int distance;
    int a_x = abs(a-x);
    int a_y = abs(a-y);
    int b_x = abs(b-x);
    int b_y = abs(b-y);
    // choose nearest teleport coord from start
    if (a_x > a_y) {
        distance += a_y;
        distance += b_x;
        if (distance < abs(a-b)) {
            cout << distance;
        } else {
            cout << abs(a-b);
        }
    } else {
        distance += a_x;
        distance += b_y;
        if (distance < abs(a-b)) {
            cout << distance;
        } else {
            cout << abs(a-b);
        }
    }
}
