#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a,b,c,d,e,f,g; cin >>a>>b>>c>>d>>e>>f>>g;
    int numbers[7] = {a, b, c, d, e, f, g};
    sort(begin(numbers), end(numbers));
    int a_ = numbers[0];
    int b_ = numbers[1];
    int sum = numbers[6];
    int c_ = sum - a_ - b_;
    cout << a_ << " " << b_ << " " << c_;

}
