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

using namespace std;
int location;



int main() {
    int N, M, K; cin >> N >> M >> K;
    int order[M];
    for (int i=0; i<M; i++) {
        cin >> order[i];
    }
    int pos[N];
    for (int i=0; i<K; i++) {
       int loc, cow; cin >> cow >> loc;
       pos[loc - 1] = cow;
    }
    bool finished = false;
    while (!finished) {
        for (int i=1; i<N; i++) {
            if (pos[i]) {
                int index = -1;
                for (int j=0; j<M; j++) {
                    if (order[j] == pos[i]) {
                        index = j;
                        break;
                    }
                }
                bool not_already = true;
                if (index != -1 && index != 0) {
                    int before = order[index - 1];
                    for (int j=0; j<N; j++) {
                        if (pos[j] == before) {
                            not_already = false;
                            break;
                        }
                    }
                    if (not_already) {
                        bool done = false;
                        int loc = i;
                        while (!done) {
                            if (pos[loc]) {
                                loc--;
                            } else {
                                pos[loc] = before;
                                done = true;
                            }
                        }
                        i=1;
                    }
                }
            }
        }
        int not_filled_counter = 0;
        for (int i=0; i<N; i++) {
            if (!pos[i]) {
                not_filled_counter++;
                location = i;
            }
        }
        if (not_filled_counter == 1) {
            finished = true;
        }
    }
    cout << location;



}