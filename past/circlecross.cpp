#include <iostream>
#include <algorithm>
//#include <cstdio>
#include <string>
#include <vector>
#include <array>

using namespace std;

bool is_duplicate(string order, int between, int first_loc, int second_loc) {
    char letter = order[between];
    for (int i=first_loc+1; i<second_loc; i++) {
        if (order[i] == letter && i != between) {
            return true;
        }
    }
    return false;
}

int main () {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);
    int counter = 0;
    string order; cin >> order;
    transform(order.begin(), order.end(), order.begin(), ::tolower);
    for (int letter=97; letter<97+26; letter++) {
        int first_loc = -1; int second_loc = -1;
        bool done = false;
        for (int loc=0; loc < 52 && !done; loc++) {
            if (order[loc] == char(letter)) {
                if (first_loc == -1) {
                    first_loc = loc;
                } else {
                    second_loc = loc;
                    done = true;
                }
            }
        }
        for (int between=first_loc+1; between<second_loc; between++) {
            if (is_duplicate(order, between, first_loc, second_loc)) {
                ;
            } else {
                counter++;
            }
        }
    }
    cout << counter / 2;
}


