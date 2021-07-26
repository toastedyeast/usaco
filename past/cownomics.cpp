#include <iostream>
#include <algorithm>
//#include <cstdio>
#include <string>
#include <vector>

using namespace std;
int counter = 0;

int main () {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    int N, M; cin >> N >> M;
    string spot_dna[N];
    string no_spot_dna[N];
    for (int i=0; i<N; i++) {
        cin >> spot_dna[i];
    }
    for (int i=0; i<N; i++) {
        cin >> no_spot_dna[i];
    }
    for (int letter=0; letter<M; letter++) {
        vector<char> genes;
        for (int cow=0; cow<N; cow++) {
            genes.push_back(spot_dna[cow][letter]);
        }
        bool duplicate = false;
        for (char gene : genes) {
            for (int cow=0; cow<N; cow++) {
                if (gene == no_spot_dna[cow][letter]) {
                    duplicate = true;
                }
            }
        }
        if (!duplicate) {
            counter++;
        }
    }
    cout << counter;
}


