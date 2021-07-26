#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int N; cin >> N;

    int grid[N][2];
    for (int i=0; i<N; i++) {
        cin >> grid[i][0];
        cin >> grid[i][1];
    }

    int current_highest = 0;
    for (int a=0; a<N; a++) {
        for (int b=0; b<N; b++) {
            for (int c=0; c<N; c++) {
                if (grid[a][1] == grid[b][1]) {
                    if (grid[c][0] == grid[a][0] || grid[c][0] == grid[b][0]) {
                        int temp = abs(grid[a][0] - grid[b][0]) * abs(grid[a][1] - grid[c][1]);
                        if (temp > current_highest) {
                            current_highest = temp;
                        }
                    }
                }
                else if (grid[a][1] == grid[c][1]) {
                    if (grid[b][0] == grid[a][0] || grid[b][0] == grid[c][0]) {
                        int temp = abs(grid[a][0] - grid[c][0]) * abs(grid[a][1] - grid[b][1]);
                        if (temp > current_highest) {
                            current_highest = temp;
                        }
                    }
                }
                else if (grid[b][1] == grid[c][1]) {
                    if (grid[a][0] == grid[b][0] || grid[a][0] == grid[c][0]) {
                        int temp = abs(grid[c][0] - grid[b][0]) * abs(grid[b][1] - grid[a][1]);
                        if (temp > current_highest) {
                            current_highest = temp;
                        }
                    }
                }
            }
        }
    }
    cout << current_highest;
}
