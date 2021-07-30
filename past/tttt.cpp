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

set<char> indiv; set<pair<char, char>> duo;


bool not_in(char a, char b) {
    if (duo.count(make_pair(a, b)) == 1 || duo.count(make_pair(b, a)) == 1) {
        return false;
    }
    return true;
}

int main() {
    freopen("tttt.in", "r", stdin);
    freopen("tttt.out", "w", stdout);
    char data[3][3];
    for (int i=0; i<3; i++) {
        string row; cin >> row;
        data[i][0] = row[0]; data[i][1] = row[1]; data[i][2] = row[2];
    }
    for (int i=0; i<3; i++) {
        char first = data[i][0];
        char second = data[i][1];
        char third = data[i][2];
        if (first == second && second == third) {
            indiv.insert(first);
        } else {
            if (first == second && not_in(first, third)) {
                duo.insert(make_pair(first, third));
            } else if (first == third && not_in(first, second)) {
                duo.insert(make_pair(first, second));
            } else if (second == third && not_in(first, second)) {
                duo.insert(make_pair(first, second));
            }
        }
    }
    for (int i=0; i<3; i++) {
        char first = data[0][i];
        char second = data[1][i];
        char third = data[2][i];
        if (first == second && second == third) {
            indiv.insert(first);
        } else {
            if (first == second && not_in(first, third)) {
                duo.insert(make_pair(first, third));
            } else if (first == third && not_in(first, second)) {
                duo.insert(make_pair(first, second));
            } else if (second == third && not_in(first, second)) {
                duo.insert(make_pair(first, second));
            }
        }
    }
    char first = data[0][0];
    char second = data[1][1];
    char third = data[2][2];
    if (first == second && second == third) {
        indiv.insert(first);
    } else {
        if (first == second && not_in(first, third)) {
            duo.insert(make_pair(first, third));
        } else if (first == third && not_in(first, second)) {
            duo.insert(make_pair(first, second));
        } else if (second == third && not_in(first, second)) {
            duo.insert(make_pair(first, second));
        }
    }
    char first2 = data[0][2];
    char third2 = data[2][0];
    if (first2 == second && second == third2) {
        indiv.insert(first2);
    } else {
        if (first2 == second && not_in(first2, third2)) {
            duo.insert(make_pair(first2, third2));
        } else if (first2 == third && not_in(first2, second)) {
            duo.insert(make_pair(first2, second));
        } else if (second == third2 && not_in(first2, second)) {
            duo.insert(make_pair(first2, second));
        }
    }
    cout << indiv.size() << endl << duo.size();
}