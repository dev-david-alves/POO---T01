#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>

#include "../testador.hpp"

int main() {

    testar(5, 6);
    testar(std::string("banana"), std::string("banana"));
    testar(std::vector<int> {1, 2, 3}, std::vector<int> {1, 2, 3});
    std::cout << std::vector<int> {1, 2, 3, 4, 5} << "\n";

    return 0;
}

