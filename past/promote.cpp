#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int values[8];

    for (int & value : values) {
        cin >> value;
    }

    int s_diff = values[3] - values[2];
    int g_diff = values[5] - values[4];
    int p_diff = values[7] - values[6];

    int s_prom = s_diff + g_diff + p_diff;
    int g_prom = g_diff + p_diff;
    cout << s_prom << endl;
    cout << g_prom << endl;
    cout << p_diff << endl;

}
