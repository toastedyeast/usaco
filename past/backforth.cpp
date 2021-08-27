#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;
set <int> results;

void change(int depth, bool forward, vector<int> barn1, vector<int> barn2, int milk1, int bucket_index) {
    if (depth == 4) {
        milk1 += barn2[bucket_index];
        results.insert(milk1);
    }
    else {
        if (forward) {
            milk1 -= barn1[bucket_index];
            barn2.push_back(barn1[bucket_index]);
            barn1.erase(barn1.begin() + bucket_index);
            for (int i=0; i<barn2.size(); i++) {
                change(depth + 1, false, barn1, barn2, milk1, i);
            }
        } else {
            milk1 += barn2[bucket_index];
            barn1.push_back(barn2[bucket_index]);
            barn2.erase(barn2.begin() + bucket_index);
            for (int i=0; i<barn1.size(); i++) {
                change(depth + 1, true, barn1, barn2, milk1, i);
            }
        }
    }
}


int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);
    vector <int> barn1; vector <int> barn2;
    for (int i=0; i<10; i++) {
        int bucket; cin >> bucket;
        barn1.push_back(bucket);
    }
    for (int i=0; i<10; i++) {
        int bucket; cin >> bucket;
        barn2.push_back(bucket);
    }
    int milk1 = 1000;
    for (int i=0; i<barn1.size(); i++) {
        change(1, true, barn1, barn2, milk1, i);
    }
    cout << results.size();
}
