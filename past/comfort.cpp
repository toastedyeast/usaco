#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    int N; cin >> N;
    bool grid[1001][1001]; int cows[N][2];
    for (int i=0; i<N; i++) {
        int x; int y;
        cin >> x >> y;
        cows[i][0] = x; cows[i][1] = y;
        grid[x][y] = true;
        int comfortable_counter = 0;
        for (int j=0; j<i+1; j++) {
            int x_coord = cows[j][0];
            int y_coord = cows[j][1];
            int neighbor_counter = 0;
            if (grid[x_coord + 1][y_coord]) neighbor_counter++;
            if (grid[x_coord - 1][y_coord]) neighbor_counter++;
            if (grid[x_coord][y_coord + 1]) neighbor_counter++;
            if (grid[x_coord][y_coord - 1]) neighbor_counter++;
            if (neighbor_counter == 3) {
                comfortable_counter++;
            }
        }
        cout << comfortable_counter << endl;
    }
}
