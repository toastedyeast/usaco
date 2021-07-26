#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>

using namespace std;


int main() {
    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);
    int N; cin >> N;
    int data[N][3];
    for (int i=0; i<N; i++){
        cin >> data[i][0] >> data[i][1] >> data[i][2];
    }
    int current_highest = 0;
    for (int loc=1; loc<4; loc++) {
        int temp_loc = loc;
        int current = 0;
        for (int swap_num=0; swap_num<N; swap_num++) {
            if (temp_loc == data[swap_num][0]) {
                temp_loc = data[swap_num][1];
                if (temp_loc == data[swap_num][2]) {
                    current++;
                }
            }
            else if (temp_loc == data[swap_num][1]) {
                temp_loc = data[swap_num][0];
                if (temp_loc == data[swap_num][2]) {
                    current++;
                }
            }
            else {
                if (temp_loc == data[swap_num][2]) {
                    current++;
                }
            }
        }
        if (current > current_highest) {
            current_highest = current;
        }
    }
    cout << current_highest;
}
