#include <iostream>
#include <algorithm>


using namespace std;

bool is_comfortable(int num, int cows[][2], int x, int y);

int main() {
    int num; cin >> num; int cows[num][2];
    for (int i=0; i<num; i++) {
        int x, y; cin >> x >> y;
        cows[i][0] = x;
        cows[i][1] = y;
        int comfortable_this_turn = 0;

        for (int j=0; j<num; j++) {
            int x_coord = cows[j][0]; int y_coord = cows[j][1];
            if (is_comfortable(num, cows, x_coord, y_coord)) {
                comfortable_this_turn++;
            }
        }
        cout << comfortable_this_turn << endl;
    }
}

bool is_comfortable(int num, int cows[][2], int x, int y) {
    int neighbors = 0;
    for (int i=0; i<num; i++) {
        if (cows[i][0] == x + 1 && cows[i][1] == y) neighbors++;
        if (cows[i][0] == x - 1 && cows[i][1] == y) neighbors++;
        if (cows[i][0] == x && cows[i][1] == y + 1) neighbors++;
        if (cows[i][0] == x && cows[i][1] == y - 1) neighbors++;
    }
    if (neighbors == 3) return true;
    else return false;
}
