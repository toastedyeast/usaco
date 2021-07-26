#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cassert>

using namespace std;

map <string, int> when_born;
string animals[12] = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};

string get_animal (int year) {
    int a = 0, y = 2021;
    while (y < year) { y++; a++; if (a == 12) a = 0; }
    while (y > year) { y--; a--; if (a == -1) a = 11; }
    return animals[a];
}

string get_animal2 (int year) {//
    int difference = year - 2021;
    if (difference > 0) {
        difference = difference % 12;
        return animals[difference];
    } else if (difference < 0) {
        difference = difference % 12;
        if (difference == 0) {
            return animals[0];
        } else {
            return animals[12 + difference];
        }
    } else return "Ox";
}

int main() {
    int num; cin >> num;
    string cows[num][8];
    when_born["Bessie"] = 2021;
    for (int i=0; i<num; i++) {
        for (int j=0; j<8; j++) {
            cin >> cows[i][j];
        }
    }
    for (int i=0; i<num; i++) {
        when_born[cows[i][0]] = when_born[cows[i][7]];
        do {
            if (cows[i][3] == "next") {
                when_born[cows[i][0]]++;
            } else {
                when_born[cows[i][0]]--;
            }
        } while (get_animal(when_born[cows[i][0]]) != cows[i][4]);
    }
    int diff = abs(when_born["Bessie"] - when_born["Elsie"]);
    cout << diff;
}
