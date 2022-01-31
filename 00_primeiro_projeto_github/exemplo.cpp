#include <iostream>

using namespace std;

auto sub(auto a, auto b) {
    return a - b;
}

int main() {

    cout << sub(12, 5) << '\n';

    return 0;
}