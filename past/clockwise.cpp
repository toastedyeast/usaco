#include <iostream>
#include <algorithm>
#include <string>


using namespace std;

string cw_or_ccw (string directions);

int main() {
    int num; cin >> num;
    for (int i=0; i<num; i++) {
        string directions; cin >> directions;
        cout << cw_or_ccw(directions) << endl;
    }
}

string cw_or_ccw (string directions) {
    int num_left = 0; int num_right = 0;
    for (int i=0; i<directions.length() - 1; i++) {
        if (directions[i] == 'E' && directions[i + 1] == 'S') num_right++;
        if (directions[i] == 'S' && directions[i + 1] == 'W') num_right++;
        if (directions[i] == 'W' && directions[i + 1] == 'N') num_right++;
        if (directions[i] == 'N' && directions[i + 1] == 'E') num_right++;

        if (directions[i] == 'E' && directions[i + 1] == 'N') num_left++;
        if (directions[i] == 'N' && directions[i + 1] == 'W') num_left++;
        if (directions[i] == 'W' && directions[i + 1] == 'S') num_left++;
        if (directions[i] == 'S' && directions[i + 1] == 'E') num_left++;
    }
    if (num_left > num_right) return "CCW";
    else return "CW";
}




